/*
Client
*/
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "fonctions.h"

int main(int argc , char *argv[])
{
	int sock,equipe;
	struct sockaddr_in server;

	//Creation socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1)
	{
		fprintf(stderr,"Creation socket impossible\n");
	}
	fprintf(stdout,"Creation socket réussie\n");

	// On part du principe que le client et le serveur sont sur la même machine (même adresse IP)
	// Sinon, il faut changer ça ci-dessous
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	// On spécifie le port TCP de communication - le même pour le client et le serveur
	server.sin_port = htons( 8888 );

	//Connection au serveur
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		fprintf(stderr,"Erreur connection impossible\n");
		close(sock);
		return 1;
	}
	char pseudo [20] = ""; char adversaire [20] = "";
	//system("clear");
	fprintf(stdout,"Connecté\n");
	//authentification
	strcpy(pseudo,authentification(sock));
	//system("clear");
	printf("Compte : %s\n\n",pseudo);
	//optionJeu
	strcpy(adversaire,optionGame(sock));
	//system("clear");
	if(!strcmp(adversaire,"msgError"))
	{
		printf("Compte : %s\n\n",pseudo);
		printf("Aucune partie n'attend de joueur, essayez d'en créer \nou d'en regarder une en attendant\n");

		close(sock);
		return 0;
	}
	//créer game
	if(!strcmp(adversaire,"succes"))
	{
		printf("Compte : %s\n\n",pseudo);
		printf("En attente d'un 2e joueur...\n\nVous serez le premier à jouer (vos pions seront les '1')");
		equipe = J1;
	}

	else
	{
		printf("Compte : %s\n\n",pseudo);
		printf("Votre adversaire est : %s\n\n (vos pions seront les '2')",adversaire);

	}
	//adversaire = "succees","userJ2","userJ1" (si pseudo est spectateur)
	Case* Damier = genJeu();
	char*  buffer= malloc(MAX_BUFFER*sizeof(char));
	char*  msg   = malloc(MAX_BUFFER*sizeof(char));
	int** coupLegaux;
	int* coup;
	int read_size;
	prettyPrintDamier(Damier);

	//jeu
	//Boucle sans fin de communication vers le serveur
	while(1)
	{
		read_size = recv(sock , buffer , MAX_BUFFER , 0);
		if(!strcmp(buffer,"DEBUT_TOUR"))
		{
			read_size = recv(sock , buffer , MAX_BUFFER , 0);
			//strcpy(msg,envoie(sock,"GAME-1-"));

			coupLegaux = transformCharToCouple(buffer);
			//On modifie localement le damier
			coup = entreeJoueur(Damier,coupLegaux);
			bougerPiece(Damier,coup[0],coup[1]);

			////system("clear");
			printf("Compte : %s\n\n",pseudo);
			prettyPrintDamier(Damier);
			//On envoie au serveur le choix du joueur
			free(coupLegaux);

			coupLegaux = ajoutTab2D(genTab2D(),coup);
			strcpy(msg,"GAME-1-");
			strcat(msg,transformCoupleToChar(coupLegaux));

			//Envoi message vers le serveur
			if( send(sock , msg , strlen(msg) , 0) < 0)
			{
				fprintf(stderr,"Echec envoi\n");
				close(sock);
				return 1;
			}
			//Ecoute pour rejouer ou non
			read_size = recv(sock , buffer , MAX_BUFFER , 0);
			while(strcmp(buffer,"FIN_TOUR"))
			{
				read_size = recv(sock , buffer , MAX_BUFFER , 0);
				//strcpy(msg,envoie(sock,"GAME-1-"));
				printf("buffer %s\n",buffer);

				coupLegaux = transformCharToCouple(buffer);
				printf("debug");
				//On modifie localement le damier
				coup = entreeJoueur(Damier,coupLegaux);
				bougerPiece(Damier,coup[0],coup[1]);

				//On envoie au serveur le choix du joueur
				free(coupLegaux);

				coupLegaux = ajoutTab2D(genTab2D(),coup);
				strcpy(msg,"GAME-1-");
				strcat(msg,transformCoupleToChar(coupLegaux));

				//Envoi message vers le serveur
				if( send(sock , msg , strlen(msg) , 0) < 0)
				{
					fprintf(stderr,"Echec envoi\n");
					close(sock);
					return 1;
				}
				read_size = recv(sock , buffer , MAX_BUFFER , 0);
			}
		}
		else if(!strcmp(buffer,"ACTUALISER"))
		{

			while(!strcmp(buffer,"ACTUALISER"))
			{
				read_size = recv(sock , buffer , MAX_BUFFER , 0);
				coupLegaux = transformCharToCouple(buffer);
				bougerPiece(Damier,coupLegaux[1][0],coupLegaux[1][1]);
				//Coup légaux et pas... CoupPlaymobil :)
				////system("clear");
				printf("ON est dans le actualiser\n");
				printf("Compte : %s\n\n",pseudo);
				prettyPrintDamier(Damier);
				read_size = recv(sock , buffer , MAX_BUFFER , 0);

			}
		}
			//recois les coups jouables coupJouables
		/*
		else if(strcmp(buffer,"ACTUALISER_DAMIER"))
		{

		}*/
		else if (read_size == 0)
		{
			utiliserCompte(pseudo,2);
			fprintf(stdout,"Déconnection %d\n",sock);
			break;
		}
		else if(read_size == -1)
		{
			fprintf(stderr,"Erreur reception\n");
			break;
		}
		//Recois prioMouvement // coups à jouer
		//Modif damier localement
		//renvois coup choisi au thread; GAME-2

		//Possibilité quitter (taper -1)
		char message_retour[MAX_BUFFER] = "";

		fprintf(stdout,"Réponse du serveur: %s\n",message_retour);
		/*
		char message[MAX_BUFFER]="" , server_reply[MAX_BUFFER]="";

		fprintf(stdout,"Saisir message : ");
		fscanf(stdin,"%s" , message);

		strcpy(server_reply,envoie(sock,message));

		fprintf(stdout,"Réponse du serveur: %s\n",server_reply);
		*/
	}

	close(sock);
	return 0;
}
