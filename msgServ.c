#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
//retourne la
/*char* envoie(char* msg)
{
	//socket oskour
	//Magie vaudou

	//envoie de msg
	char* msgRecu = malloc(sizeof(char));
	//attente msg de reception
	strcat(msgRecu,"authenOui");

	return msgRecu;
}*/
//envoie pour test authentification
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
}
char* connexion()
{
	//Reception liste username
	char* idClient = envoie("0-SYS-0");

	if(strcmp(idClient,"erreurMsg") == 0)
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
	envoie(msg);
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
					//system("clear");
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
					printf("DEBUG \n");
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


int main()
{
	char* tmp = malloc(sizeof(char));
	strcat(tmp,"123456");
	authentification(tmp);
	return 0;
}
