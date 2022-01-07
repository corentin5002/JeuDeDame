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

#include "fonctions.h"
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

		Args* argsThread = malloc(sizeof(struct Args));
		Partie* ListePartie = genListePartie();
		int * tmp = malloc(sizeof(int));
		*tmp = 0;
		argsThread->Lpartie = ListePartie;
		argsThread->idClient= client_sock;
		argsThread->numGuest= tmp;

		if( pthread_create( &sniffer_thread , NULL ,  traitement_connection , (void*)argsThread) < 0)
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
void *traitement_connection(void *argsThread)
{
	Args* nv = argsThread;
	int index = indexCreerPartie(nv->Lpartie);
	Partie* Session = &nv->Lpartie[index];
	int sock = nv->idClient;
	char pseudo[20] = "";
	int read_size;

	#ifdef DEBUG
	fprintf (stdout,"Client %d\t - connection établie\n",sock);
	#endif

	//Reception du message du client
	while( 1 )
	{
		char msgRecu[MAX_BUFFER]="";

		//Renvoi du même message
		if ((read_size = recv(sock , msgRecu , MAX_BUFFER , 0)) > 0)
		{
			//
			fprintf (stdout,"Client %d\t - Message:%s\n",sock,msgRecu);
		}
		else if (read_size == 0)
		{
			utiliserCompte(pseudo,2);
			fprintf(stdout,"Déconnection client %d\n",sock);
			free(argsThread);
			break;
		}
		else if(read_size == -1)
		{
			fprintf(stderr,"Erreur reception\n");
			free(argsThread);
			break;
		}
		//Aiguillage des messages clients
		char* type = strtok(msgRecu,"-");
		char* code = strtok(NULL,"-");

		char  msgRetour[MAX_BUFFER] ="";

		//Connexion ou déconnexion
		if(!strcmp(type,"SYS"))
		{
			int intCode = atoi(code);
			char* info = strtok(NULL,"-");
			int test;
			switch (intCode) {
				case 0:
					printf("On quitte le serveur et on signale que notre idClient est libre\n");
					printf("retour: DECO \n");
					break;
				case 20:
					//Verif si l'authentification est possible (useless ?)
					printf("Test authentification possible\n\n");
					strcpy(msgRetour,"authenOui");
					break;
				case 200:
					//Si le pseudo existe dans la BD
					test = utiliserCompte(info,0);
					if(test)
					{
						strcpy(pseudo,info);
						strcpy(msgRetour,"succes");
					}
					//Sinon
					else strcpy(msgRetour,"erreurPseudo");
					break;
				case 201:
					//Si le pseudo n'est pas dans la BD
					test = utiliserCompte(info,1);
					if(test)
					{
						strcpy(pseudo,info);
						strcpy(msgRetour,"succes");
					}
					//Sinon
					else strcpy(msgRetour,"erreurPseudo");
					break;
				case 202:
					//Retourne un pseudo généré aléatoirement
					strcpy(pseudo,genGuest(nv->numGuest));
					strcpy(msgRetour,pseudo);
					printf("%s\n",msgRetour);

					break;
				default:
					printf("DEBUG Message inconnue (mauvais format)\n");
					break;
			}
		}
		write(sock , msgRetour , strlen(msgRetour));
	}
	return 0;
}
