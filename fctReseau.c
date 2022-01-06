#include "fctReseau.h"

//retourne la
char* envoie(char* msg)
{
	//socket oskour
	//Magie vaudou

	//envoie de msg
	return triageArrivee(msg);
	//attente msg de reception
}
/*//envoie pour test authentification
char* envoie(char* msg)
{
	printf("DEBUG %s\n",msg);
	char* win = malloc(sizeof(char));
	strcat(win,"succes");
	char* lose = malloc(sizeof(char));
	strcat(lose,"erreurPseudo");

	char* auth = malloc(sizeof(char));
	strcat(auth,"authenOui");

	if (!strcmp("123456-SYS-20",msg))
		return auth;
	else if(!strcmp("123456-SYS-200-eric",msg))
		return win;
	else return lose;
}*/
char* connexion()
{
	//Reception liste username

	char* idClient = malloc(sizeof(char));
	strcat(idClient,"0-SYS-0");
	idClient = envoie(idClient);

	if(!strcmp(idClient,"erreurMsg"))
	{
		//char tmp = malloc(sizeof(char));
		return "erreurMsg";
	}
	//manipulation de idClient pour garder que idClient

	return idClient;
}

char* deconnexion(char* idClient)
{
	char* msg = strcat(idClient,"-SYS-1");
	envoie(msg); //renvoie

	return "yaya2";
}

char* authentification(char* idClient)
{

	char* msg = malloc(sizeof(char));
	strcat(msg,idClient);
	strcat(msg,"-SYS-20");
	msg = envoie(msg);

	if(strcmp(msg,"authenOui") == 0)
	{
		//printf("DEBUG \n");
		printf(	"Vous voulez :\n"
				""
				"0- utiliser un compte déjà existant.\n"
				"1- créer un nouveau compte.\n"
				"2- utiliser un compte invité.\n");

		int test = FALSE;
		int retour = TRUE;
		char* pseudo = malloc(21*sizeof(char));
		while(retour)
		{
			int choix = 1000;
			retour = FALSE;
			while(1)
			{
				if(choix>=0 && choix<3) break;
				if(choix != 1000 && test)
				{
					system("clear");
					printf("L'option n° %d n'est pas disponible\n",choix);
					printf(	"Vous voulez :\n"
							""
							"0- utiliser un compte déjà existant.\n"
							"1- créer un nouveau compte.\n"
							"2- utiliser un compte invité.\n");
				}
				test = TRUE;
				printf("\nOption : ");
				scanf("%d",&choix);
			}
			//system("clear");
			switch (choix) {
				case 0:
					//Compte existant
					while(1)
					{
						if(strcmp(msg,"succes") == 0) break;
						if(strcmp("erreurPseudo",msg) == 0)
						{
							printf("Le pseudo '%s' n'existe pas, réessayez\n"
									"ou tapez '0' pour retourner à l'étape précédente\n",pseudo);
						}
						printf("Rentrez votre pseudo pour le compte (max 20 caractères):");
						scanf("%s",pseudo);

						if(strcmp(pseudo,"0") == 0)
						{
							retour = TRUE;
							break;
						}
						strcpy(msg,"");
						strcat(msg,idClient);
						strcat(msg,"-SYS-200-");
						strcat(msg,pseudo);
						msg = envoie(msg); // retourne msg = "erreurPseudo" ou "succes"
					}
					break;
				case 1:
					//Créer compte
					while(1)
					{
						if(strcmp(msg,"succes") == 0) break;
						if(strcmp("erreurPseudo",msg) == 0)
						{
							//system("clear");
							printf("Le pseudo '%s' existe déjà, réessayez\n"
									"ou tapez '0' pour retourner à l'étape précédente\n",pseudo);
						}
						printf("Rentrez votre pseudo pour le compte (max 20 caractères):");
						scanf("%s",pseudo);

						if(strcmp(pseudo,"0") == 0)
						{
							retour = TRUE;
							break;
						}
						strcpy(msg,"");
						strcat(msg,idClient);
						strcat(msg,"-SYS-201-");
						strcat(msg,pseudo);
						msg = envoie(msg); // retourne msg = "erreurPseudo" ou "succes"
					}
					break;

				case 2:
					//compte invité
					strcat(msg,idClient);
					strcat(msg,"-SYS-202");
					pseudo = envoie(msg); //retourne guest#### ex: guest2546
					break;
				default:
					break;
			}
		}
		return pseudo;
	}
	return "errorAuthentification";
}

char* creationPartie(char * idClient){
	return "test";
}
char* jeuPartie(char * idClient, int equipe){
	return "test";
}
char* rejoindreSession(char * idClient){
	return "test";
}
char* rejoindrePartie(char * idPartie, int partie){
	return "test";
}
char* regarderSession(char * idClient){
	return "test";
}
char* regarderPartie(char * idPartie){
	return "test";
}

char* optionGame(char * idClient)
{
	printf("Vous voulez jouer, très bien :\n");
	printf("Que voulez vous faire ?\n");
	printf("0.Créer une nouvelle partie,\n");
	printf("1.Rejoindre une partie,\n");
	printf("2.Regarder une partie en cours,\n");
	printf("3.Quitter le jeu.\n");

	int reponse = -1;
	int cmpRep = 5;
	scanf("%d", &reponse);
	while((reponse >= 0 && reponse <= 3) || (cmpRep != 0))
	{
		printf("Veuillez mettre une instruction valide, "
		"il vous reste %d essaie(s) avant d'être éjecté du jeu.\n", cmpRep);
		scanf("%d", &reponse);
		cmpRep --;
	}

	//Definition d'une chaine permettant de récuperer le retour des foctions intermédiares.
	char * msg = malloc(sizeof(char));


	switch (reponse)
	{
		//Créer une nouvelle partie
		case 0:
			strcat(msg,creationPartie(idClient));
			if(strcmp(msg,"msgError") != 0)
			{
				printf("Veuillez choisir quelle couleur vous voulez jouer :\n");
				printf("0.Blanc,\n1.Noir.\n");

				//Attente de la réponse,
				int equipe = 0;
				cmpRep = 5;
				scanf("%d", &equipe);
				while((equipe < 0 && equipe > 3) || (cmpRep != 0))
				{
					printf("Veuillez mettre une instruction valide, "
					"il vous reste %d essaie(s) avant d'être éjecté du jeu.\n", cmpRep);
					scanf("%d", &equipe);
					cmpRep --;
				}
				//Si on sort car trop d'essaies, alors on sort du if pour appeler la fonction deconnexion
				if(cmpRep == 0) break;
				jeuPartie(idClient, equipe);
			}
			printf("Impossible de créer la partie, déconnection.\n");
			deconnexion(idClient);
			break;
		//Rejoindre une partie
		case 1:
			strcat(msg,rejoindreSession(idClient));
			//Retour de la forme 0-idClient1-1-idClient2.....
			if(strcmp(msg,"msgError") != 0)
			{
				int nbPartie = 0;
				printf("Veuillez choisir quelle partie vous voulez rejoindre :\n");
				char * joliePrint = strtok(msg, "-");
				while(joliePrint != NULL)
				{
					printf("Partie n°%s : ", joliePrint);
					joliePrint = strtok(NULL, "-");
					printf("Jouer avec le joueur : %s\n", joliePrint);
					joliePrint = strtok(NULL, "-");
					nbPartie ++;
				}

				//Attente de la réponse,
				int partie = 0;
				cmpRep = 5;
				scanf("%d", &partie);
				while((partie >= 0 && partie <= nbPartie) || (cmpRep != 0))
				{
					printf("Veuillez mettre une instruction valide,"
					"il vous reste %d essaie(s) avant d'être éjecté du jeu.\n", cmpRep);
					scanf("%d", &partie);
					cmpRep --;
				}
				if(cmpRep == 0) break;
				rejoindrePartie(idClient, partie);
			}
			printf("Impossible de créer la partie, déconnection.\n");
			deconnexion(idClient);
			break;
		//Regarder une partie
		case 2:
			strcat(msg,rejoindreSession(idClient));
			//Retour de la forme 0-idClienta1/idClienta2-1-idClientb1/idClientb2.....
			if(strcmp(msg,"msgError") != 0)
			{
				int nbPartie = 0;
				printf("Veuillez choisir quelle partie vous voulez rejoindre :\n");
				char * joliePrint = strtok(msg, "-");
				while(joliePrint != NULL)
				{
					printf("Partie n°%s : ", joliePrint);
					joliePrint = strtok(NULL, "-");
					printf("Jouer avec le joueur : %s\n", joliePrint);
					joliePrint = strtok(NULL, "-");
					nbPartie ++;
				}

				//Attente de la réponse,
				int partie = 0;
				cmpRep = 5;
				scanf("%d", &partie);
				while((partie >= 0 && partie <= nbPartie) || (cmpRep != 0))
				{
					printf("Veuillez mettre une instruction valide,"
					"il vous reste %d essaie(s) avant d'être éjecté du jeu.\n", cmpRep);
					scanf("%d", &partie);
					cmpRep --;
				}
				if(cmpRep == 0) break;
				rejoindrePartie(idClient, partie);
			}
			printf("Impossible de créer la partie, déconnection.\n");
			deconnexion(idClient);
			break;
		//Fin du jeu
		default:
			printf("Vous quitter le jeu, merci d'avoir jouer.\n");
			deconnexion(idClient);
			break;
	}
	return "yaya";
}

/*
	creationGame   -> idClient-SYS-220
	rejoindreLobby -> idClient-SYS-221
		rejoindreGame ->
	regarderLobby  -> idClient-SYS-222
		regarderGame  ->
	quitter -> Requête Identique à Déco
*/



char* triageArrivee(char* msgRecu)
{
	char* idClient = strtok(msgRecu,"-");
	char* type = strtok(NULL,"-");
	char* code = strtok(NULL,"-");
	char* msgRetour = malloc(sizeof(char));

	//Connexion ou déconnexion
	if(!strcmp(idClient,"0") || !strcmp(code,"1"))
	{
		//Si on demande à se connecter
		if(!strcmp(code,"0"))
		{
			//récupérer son IdClient et lui envoyé
			char* tmp = malloc(sizeof(char));
			if(0) strcat(tmp,"erreurMsg");
			else strcat(tmp,"123456");
			return tmp;
		}
		//Sinon c'est qu'on veut se déconnecter
		else
		{
			printf("On quitte le serveur et on signale que notre idClient est libre\n");
			return NULL;
		}
	}
	else
	{
		if(!strcmp(type,"SYS"))
		{
			int intCode = atoi(code);
			char* pseudo = strtok(NULL,"-");
			switch (intCode) {
				case 20:
					//Verif si l'authentification est possible (useless ?)
					printf("Test authentification possible\n\n");
					strcat(msgRetour,"authenOui");
					break;
				case 200:
					//Si le pseudo existe dans la BD
					if(1) strcat(msgRetour,"succes");
					//Sinon
					else strcat(msgRetour,"erreurPseudo");
					break;
				case 201:
					//Si le pseudo n'est pas dans la BD
					if(1) strcat(msgRetour,"succes");
					//Sinon
					else strcat(msgRetour,"erreurPseudo");
					break;
				case 202:
					//Retourne un pseudo généré aléatoirement
					strcat(msgRetour,"guest");
					strcat(msgRetour,"####");
					break;
				default:
					break;
			}
		}
		return msgRetour;
	}
}
//Ajout d'une chaine de caractère à la fin du fichier.
void ajoutCompte(FILE* fichier,char* chaine)
{
	fseek(fichier, 0, SEEK_END);
	fputc('-',fichier);
	fputs(chaine,fichier);
	fputs("\n",fichier);
	fseek(fichier, 0, SEEK_SET);
}

void decoReco(FILE* fichier,long curseur,char nvChar)
{
	fseek(fichier,curseur,SEEK_SET);
	fputc(nvChar,fichier);
	fseek(fichier, 0, SEEK_SET);
}

int utiliserCompte(char* compte,int mode)
{
	FILE* fichier = fopen("comptes","r+");
	char* buff = malloc(22*sizeof(char));
	char* modifCompte=malloc(22*sizeof(char));
	strcat(modifCompte,"-");
	strcat(modifCompte,compte);
	//Trouver un pseudo existant dans le fichier
	if(mode == 0)
	{
		while(fscanf(fichier,"%s\n",buff) != -1)
		{
			//Si on détecte le nom dans la base de donnée
			if(buff[0]=='-' && !strcmp(modifCompte,buff))
			{
				fseek(fichier,-strlen(compte)-2,SEEK_CUR);
				decoReco(fichier,ftell(fichier),'+');
				free(fichier);
				return 1;
			}
		}
	}
	//Créer un nouveau compte n'existant pas dans le fichier
	else if(mode == 1)
	{
		int test = 1;
		char* enCours= malloc(sizeof(char));
		strcat(enCours,"*");
		strcat(enCours,compte);
		while(fscanf(fichier,"%s\n",buff) != -1)
		{

			if(!strcmp(compte,buff))
			{
				//Si on détecte le nom de compte dans la BD
				test = 0;
				break;
			}
			else if(!strcmp(enCours,buff))
			{
				//Si on détecte le nom de compte dans la BD et qu'il est déjà connecté
				test = 0;
				break;
			}
		}
		//Si le nom de compte n'a pas été trouvé
		if(test)
		{
			printf("DEBUG %s\n",compte);
			ajoutCompte(fichier,compte);
			free(fichier);
			return 1;
		}
	}
	else
	{
		fprintf(stderr,"Erreur: mode invalide pour fonction utiliserCompte\n");
	}
	free(fichier);
	return 0;
}

int main()
{
	system("clear");
	char* tmp = malloc(sizeof(char));
	strcat(tmp,"123456");
	//authentification(tmp);
	char* idClient = connexion();

	char* pseudo = authentification(idClient);
	printf("pseudo : %s\n",pseudo);

	return 0;
}
