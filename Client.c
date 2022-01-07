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
	int sock;
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

	fprintf(stdout,"Connecté\n");
	//authentification
	//optionJeu
	//jeu
	//Boucle sans fin de communication vers le serveur
	while(1)
	{
		char message[MAX_BUFFER]="" , server_reply[MAX_BUFFER]="";

		fprintf(stdout,"Saisir message : ");
		fscanf(stdin,"%s" , message);

		strcpy(server_reply,envoie(sock,message));

		fprintf(stdout,"Réponse du serveur: %s\n",server_reply);
	}

	close(sock);
	return 0;
}
