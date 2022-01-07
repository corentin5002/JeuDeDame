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
	Args* argsThread = malloc(sizeof(struct Args));
	//Partie* ListePartie = genListePartie();
	int * tmp = malloc(sizeof(int));
	*tmp = 0;
	argsThread->Lpartie = genListePartie();
	argsThread->numGuest= tmp;
	while( (client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c)) )
	{
		argsThread->idClient= client_sock;
		//#ifdef DEBUG
		fprintf(stdout,"Connection acceptée - Client %d\n",client_sock);
		//#endif
		pthread_t sniffer_thread;
		new_sock = malloc(1);

		//avant malloc ici
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
	free(argsThread);
	close(socket_desc);
	return 0;
}

/*
 * Fonction qui traite les receptions/transmissions pour chaque client
 * */
void *traitement_connection(void *argsThread)
{
	Args* nv = (Args*)argsThread;
	int sock = nv->idClient;
	int index,equipe;

	Partie* Session = NULL;
	//int sock = nv->idClient;
	char pseudo[20] = "";
	int read_size;
	int test = FALSE;


	#ifdef DEBUG
	fprintf (stdout,"Client %d\t - connection établie\n",sock);
	#endif

	//Reception du message du client
	while( 1 )
	{
		char msgRecu[MAX_BUFFER]="";
		//Cas premier tour : la partie possède les deux joueurs

		//while(1)
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
			break;
		}
		else if(read_size == -1)
		{
			fprintf(stderr,"Erreur reception\n");
			free(argsThread);
			break;
		}
		//Aiguillage des messages clients
		printf("MSGRECU %s\n",msgRecu);

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
					printf("Serveur envoie %s\n",msgRetour);

					break;
				case 220:
					index = indexCreerPartie(nv->Lpartie);

					if(index!=-1)
					{
						strcpy(msgRetour,"succes");
						printf("msgRetour %s INDEX %d\n",msgRetour,index);

						Session = &nv->Lpartie[index];
						nv->Lpartie[index].idJ1 = sock;
						nv->Lpartie[index].userJ1=pseudo;
						equipe = J1;
					}
					else strcpy(msgRetour,"msgError");
					break;
				case 2210:
					//rejoindre -> client recup str de pseudo
					strcpy(msgRetour,listePartieRejoindre(nv->Lpartie));
					//Si pas de partie dispo la fonction renvoie une chaine vide
					if(!strcmp(msgRetour,""))
						strcpy(msgRetour,"msgError");
					break;
				case 2211:
					//rejoindre -> client renvoie sa décision
					index = indexPartieDpPseudo(nv->Lpartie,info);
					Session = &nv->Lpartie[index];
					Session->idJ2  = sock;
					Session->userJ2= pseudo;
					Session->tourActu = J1;
					equipe = J2;
					//Envoie des premiers coups du J1
					int** coupLegaux = prioMouvement(Session->Damier,J1);
					char* msg = malloc(MAX_BUFFER*sizeof(char));
					strcpy(msg,"DEBUT_TOUR");

					if(write(Session->idJ1, msg , strlen(msg)) == -1)
					{
						printf("DEBUG envoie impossible\n");
					}

					strcpy(msg,transformCoupleToChar(coupLegaux));
					printf("\n\nenvoie msg%d\n\n",Session->idJ1);

					if(write(Session->idJ1, msg , strlen(msg)) == -1)
					{
						printf("DEBUG envoie impossible\n");
					}

					strcpy(msgRetour,Session->userJ1);
					if(write(Session->idJ2, msgRetour , strlen(msgRetour)) == -1)
					{
						printf("DEBUG envoie impossible\n");
					}
					printf("client%d Session : %d\n",sock,index);
					strcpy(msgRetour,"ACTUALISER");
					printf("MSGRETOUR ____ %s\n",msgRetour);

					break;
				case 2220:
					//regarder -> client recup str de pseudo
					break;
				case 2221:
					//regarder -> client renvoie sa décision
					//Il faut set sa session
					break;

				default:
					printf("DEBUG Message inconnue (mauvais format)\n");
					break;
			}
		}
		else if(!strcmp(type,"GAME"))
		{
			int intCode = atoi(code);
			char* info = malloc(MAX_BUFFER*sizeof(char));
			int** Gcoup;
			switch(intCode)
			{
				//debut tour du joueur
				case 1:
					strcpy(info,strtok(NULL,""));
					Gcoup = transformCharToCouple(info);
					bougerPiece(Session->Damier,Gcoup[1][0],Gcoup[1][1]);
					int* direct = direction(Gcoup[1][0]);
					for(int i=0;i<4;i++)
					{
						int voisin = Gcoup[1][0] + direct[i];
						int* directVoisin = direction(voisin);
						if (Gcoup[1][1] == voisin)
						{
							//coup terminal
							Session->tourPrec = Session->tourActu;
							Session->tourActu = adversaire(Session,Session->tourActu);

							printf("Fin du tour pour client%d",sock);
							//Envoie des premiers coups du J1
							int** coupLegaux = prioMouvement(Session->Damier,(equipe%2)+1);
							char* msg = transformCoupleToChar(coupLegaux);

							if(write(Session->tourActu, msg , strlen(msg)) == -1)
							{
								fprintf(stderr,"Erreur envoie message impossible\n");
							}
							printf("client%d Session : %d\n",sock,index);
							strcpy(msgRetour,"FIN_TOUR");
						}
						else if (Gcoup[1][1] == voisin + directVoisin[i])
						{
							//On a mangé un piond donc
							//write()
							printf("On fait des verife %d\n",adversaire(Session,sock));

						}
					}
					break;
				//coup du joueur
				case 2:

					//J2 recois le coup

					//if(coup terminal)
					//envoie(j2,'a toi')
					//->
					break;
				default:
					break;

			}
		}
		printf("Message retourné à client%d : %s\n",sock,msgRetour);
		if(test) write(Session->tourActu , msgRetour , strlen(msgRetour));
		else     write(sock  			 , msgRetour , strlen(msgRetour));
	}

	return 0;
}
