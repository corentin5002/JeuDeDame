/*
	Serveur :
	1) Utilise une socket TCP
	2) Utilise des threads pour permettre la connection de plusieurs clients
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

#define MAX_BUFFER 2000
#define TAILLE_FILE 3
//#define DEBUG 1

//La fonction passée en argument de thread sera toujours void* avec un seul argument void*
void *traitement_connection(void *);

int main(int argc , char *argv[])
{
	int socket_desc , client_sock , c , *new_sock;
	struct sockaddr_in server , client;

	fprintf(stdout,"Lancement serveur Jeux de Dames...\n");

	//Creation socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1)
	{
		fprintf(stderr,"Creation socket impossible\n");
	}
	#ifdef DEBUG
	fprintf(stdout,"Creation socket réussie\n");
	#endif

	//On initialise la structure sockaddr_in
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
  // Il faut choisir un port TCP non utilisé
	// On spécifie le port TCP de communication - le même pour le client et le serveur
	server.sin_port = htons( 8888 );

	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		fprintf(stderr,"Erreur bind impossible\n");
		close(socket_desc);
		return 1;
	}
  #ifdef DEBUG
	fprintf(stdout,"Bind réussi\n");
  #endif

	//Listen
	if ( listen(socket_desc , TAILLE_FILE) !=0)
		{
			fprintf(stderr,"Erreur listen\n");
			close(socket_desc);
			return 1;
		}

	//Attente des connections entrantes
	fprintf(stdout,"\nEn attente de connection client...\n");

	c = sizeof(struct sockaddr_in);
	while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
	{
		//#ifdef DEBUG
		fprintf(stdout,"Connection acceptée - Client %d\n",client_sock);
		//#endif
		pthread_t sniffer_thread;
		new_sock = malloc(1);
		*new_sock = client_sock;

		if( pthread_create( &sniffer_thread , NULL ,  traitement_connection , (void*) new_sock) < 0)
		{
			fprintf(stderr,"\nImpossible de créer un thread");
			return 1;
		}
		#ifdef DEBUG
		fprintf(stdout,"\nThread créée\n");
		#endif
	}

	if (client_sock < 0)
	{
		fprintf(stderr,"Erreur connection client\n");
		close(socket_desc);
		return 1;
	}
 	close(socket_desc);
	return 0;
}

/*
 * Fonction qui traite les receptions/transmissions pour chaque client
 * */
void *traitement_connection(void *socket_desc)
{
	int sock = *(int*)socket_desc;
	int read_size;

	#ifdef DEBUG
	fprintf (stdout,"Client %d\t - connection établie\n",sock);
	#endif

	//Reception du message du client
	while( 1 )
	{
		char client_message[MAX_BUFFER]="";

		//Renvoi du même message
		if ((read_size = recv(sock , client_message , MAX_BUFFER , 0)) > 0)
		{
			fprintf (stdout,"Client %d\t - Message:%s\n",sock,client_message);
			write(sock , client_message , strlen(client_message));
		}
		else if (read_size == 0)
		{
			fprintf(stdout,"Déconnection client %d\n",sock);
			free(socket_desc);
			break;
		}
		else if(read_size == -1)
		{
			fprintf(stderr,"Erreur reception\n");
			free(socket_desc);
			break;
		}
	}

	return 0;
}
