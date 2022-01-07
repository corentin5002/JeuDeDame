#include "fonctions.h"

//------------------------------------------------------------------------------
//Fonction de génération d'un damier de taille 10x10
//Retourne un pointeur sur un tableau une dimension de 50 Case.
Case * genJeu()
{
	Case * Damier = malloc(50*sizeof(Case));
	int i;
	//initialisation du Damier
	for(i=0;i<50;i++){
		if (i < 20)
		{
			Damier[i].equipe= J2;
		}
		else if (i > 29)
		{
			Damier[i].equipe= J1;
		}
		else Damier[i].equipe= CASE;
		Damier[i].dame  = FALSE;
		Damier[i].etat 	= TRUE;
	}
	return Damier;
}
//------------------------------------------------------------------------------
void bougerPiece(Case* Damier,int cDepart,int cArrivee)
{
	int* direct = direction(cDepart);
	for(int i=0;i<4;i++)
	{
		int voisin = cDepart + direct[i];
		int* directVoisin = direction(voisin);
		if (cArrivee == voisin)
		{
			Damier[cArrivee].equipe = Damier[cDepart].equipe;
			Damier[cDepart].equipe = CASE;
			break;
		}
		else if (cArrivee == voisin + directVoisin[i])
		{
			Damier[cArrivee].equipe = Damier[cDepart].equipe;
			Damier[cDepart].equipe  = CASE;
			Damier[voisin].equipe	= CASE;
			break;
		}
	}
}
//------------------------------------------------------------------------------
void prettyPrint(Case* Damier)
{
	printf("| ");
	int i;
	for(i=0;i<50;i++)
	{
		printf("%d ",Damier[i].equipe);
		if (i%5 == 4) printf("|\n| ");
	}
	printf("\b\b \n");
}
//------------------------------------------------------------------------------
void prettyPrintDamier(Case* Damier)
{
	printf("\n  x 0 1 2 3 4 5 6 7 8 9");
	printf("\ny -----------------------\n");
	int i,compt;
	compt=0;
	printf("%d | ",compt++);
	for(i=0;i<50;i++)
	{
		//on extrait le numéro de la ligne
		int numL = (i-i%5)/5;
		//Si la ligne est paire
		if (numL%2 == 0) printf("  %d ",Damier[i].equipe);
		//Si la ligne est impaire
		else printf("%d   ",Damier[i].equipe);
		if (i%5 == 4 && compt<10)
			printf("|\n%d | ",compt++);
		else if(i%5 == 4) printf("|\n ");
	}
	printf("\b  -----------------------\n");

}
//------------------------------------------------------------------------------
void prettyPrintDamierChiffre(Case* Damier)
{
	printf("\n_______________________\n");
	printf("| ");
	int i;
	for(i=0;i<50;i++)
	{
		//on extrait le numéro de la ligne
		int numL = (i-i%5)/5;
		if(numL<2)
		{
			//Si la ligne est paire
			if (numL%2 == 0) printf("   %d ",i);
			//Si la ligne est impaire
			else printf(" %d   ",i);
			if (i%5 == 4) printf("|\n| ");
		}
		else
		{
			//Si la ligne est paire
			if (numL%2 == 0) printf("  %d ",i);
			//Si la ligne est impaire
			else printf("%d   ",i);
			if (i%5 == 4) printf("|\n| ");
		}
	}
	printf("\b\b");
	printf("_______________________\n");

}
//------------------------------------------------------------------------------
void prettyPrintPassage(Case* Damier)
{
	printf("\n_______________________\n");
	printf("| ");
	int i;
	for(i=0;i<50;i++)
	{
		//on extrait le numéro de la ligne
		int numL = (i-i%5)/5;
		//Si la ligne est paire
		if (numL%2 == 0) printf("  %d ",Damier[i].etat);
		//Si la ligne est impaire
		else printf("%d   ",Damier[i].etat);
		if (i%5 == 4) printf("|\n| ");
	}
	printf("\b\b");
	printf("_______________________\n");

}
//------------------------------------------------------------------------------
void damierType1(Case * Damier,int tailleDamier)
{
	Case caseTest;
	caseTest.equipe = CASE;
	caseTest.dame   = FALSE;
	caseTest.etat   = TRUE;
	for (int i=0; i<tailleDamier; i++)
	{
		setCase(Damier,i,caseTest);
	}
	caseTest.equipe = J1;
	setCase(Damier,27,caseTest);
	caseTest.equipe = J2;
	setCase(Damier,21,caseTest);
	setCase(Damier,22,caseTest);
	setCase(Damier,11,caseTest);

	printf(" Damier actuel type 1\n");
	prettyPrintDamier(Damier);
}
//------------------------------------------------------------------------------
void damierType2(Case * Damier,int tailleDamier)
{
	Case caseTest;
	caseTest.equipe = CASE;
	caseTest.dame   = FALSE;
	caseTest.etat   = TRUE;
	for (int i=0; i<tailleDamier; i++)
	{
		setCase(Damier,i,caseTest);
	}
	caseTest.equipe = J1;
	setCase(Damier,27,caseTest);
	caseTest.equipe = J2;
	setCase(Damier,21,caseTest);
	setCase(Damier,22,caseTest);
	setCase(Damier,11,caseTest);
	setCase(Damier,12,caseTest);


	printf(" Damier actuel type 2\n");
	prettyPrintDamier(Damier);
}
//------------------------------------------------------------------------------
void damierType3(Case * Damier,int tailleDamier)
{
	Case caseTest;
	caseTest.equipe = CASE;
	caseTest.dame   = FALSE;
	caseTest.etat   = TRUE;
	for (int i=0; i<tailleDamier; i++)
	{
		setCase(Damier,i,caseTest);
	}
	caseTest.equipe = J1;
	setCase(Damier,44,caseTest);
	caseTest.equipe = J2;
	setCase(Damier,39,caseTest);
	setCase(Damier,28,caseTest);
	setCase(Damier,29,caseTest);
	setCase(Damier,12,caseTest);


	printf(" Damier actuel type 3\n");
	prettyPrintDamier(Damier);
}
//------------------------------------------------------------------------------
void damierType4(Case * Damier,int tailleDamier)
{
	Case caseTest;
	caseTest.equipe = J2;
	caseTest.dame   = FALSE;
	caseTest.etat   = TRUE;
	setCase(Damier,26,caseTest);
	printf(" Damier actuel type 3\n");
	prettyPrintDamier(Damier);
}
//------------------------------------------------------------------------------
void damierType5(Case * Damier,int tailleDamier)
{
	Case caseTest;
	caseTest.equipe = CASE;
	caseTest.dame   = FALSE;
	caseTest.etat   = TRUE;
	for (int i=0; i<tailleDamier; i++)
	{
		setCase(Damier,i,caseTest);
	}
	caseTest.equipe = J1;
	setCase(Damier,1,caseTest);
	caseTest.equipe = J2;
	setCase(Damier,48,caseTest);

	printf(" Damier actuel type 2\n");
	prettyPrintDamier(Damier);
}
//------------------------------------------------------------------------------
void setCase(Case* Damier,int coord,Case cNvl)
{
	Damier[coord].equipe = cNvl.equipe;
	Damier[coord].dame   = cNvl.dame;
	Damier[coord].etat   = cNvl.etat;
}
//------------------------------------------------------------------------------
int ennemie(Case pion)
{
	return (pion.equipe == J1) ? J2 : J1;
}
//------------------------------------------------------------------------------
Case* cpyDamier(Case* Damier)
{
	Case * DamierR = malloc(50*sizeof(Case));
	memcpy(DamierR,Damier,50);
	for(int i=0;i<50;i++)DamierR[i] = Damier[i];
	return DamierR;
}
//------------------------------------------------------------------------------
int* direction(int coordP)
{
	//Determine si on est sur ligne paire ou impaire
	int numLigne = (coordP-coordP%5)/5;
	int* direct = malloc(4*sizeof(int));

	//Coin en Haut à droite
	if (coordP == 4)
	{
		int tmp[4]={0,0,0,5};
		for (int i = 0; i < 4; i++) direct[i] = tmp[i];
	}
	//Coin en Bas à gauche
	else if (coordP == 45)
	{
		int tmp[4]={0,-5,0,0};
		for (int i = 0; i < 4; i++) direct[i] = tmp[i];
	}
	//Ligne du Haut
	else if (numLigne == 0)
	{
		int tmp[4]={0,0,6,5};
		for (int i = 0; i < 4; i++) direct[i] = tmp[i];
	}
	//Ligne du Bas
	else if (numLigne == 9)
	{
		int tmp[4]={-6,-5,0,0};
		for (int i = 0; i < 4; i++) direct[i] = tmp[i];
	}
	//Colonne de Droite
	else if (coordP % 10 == 4)
	{
		//Case sur les lignes paires
		if (numLigne%2 == 0)
		{
			int tmp[4]={-5,0,0,5};
			for (int i = 0; i < 4; i++) direct[i] = tmp[i];
		}
		//Case sur les lignes impaires
		else
		{
			int tmp[4]={-6,0,0,4};
			for (int i = 0; i < 4; i++) direct[i] = tmp[i];
		}
	}
	//Colonne de Gauche
	else if (coordP % 10 == 5)
	{
		//Case sur les lignes paires
		if (numLigne%2 == 0)
		{
			int tmp[4]={0,-4,6,0};
			for (int i = 0; i < 4; i++) direct[i] = tmp[i];
		}
		//Case sur les lignes impaires
		else
		{
			int tmp[4]={0,-5,5,0};
			for (int i = 0; i < 4; i++) direct[i] = tmp[i];
		}
	}
	//Case sur les lignes paires
	else if (numLigne%2 == 0)
	{
		int tmp[4]={-5,-4,6,5};
		for (int i = 0; i < 4; i++) direct[i] = tmp[i];
	}
	//Case sur les lignes impaires
	else
	{
		int tmp[4]={-6,-5,5,4};
		for (int i = 0; i < 4; i++) direct[i] = tmp[i];

	}

	return direct;
}
//------------------------------------------------------------------------------
int** ajoutTab2D(int** Tab2D,int* tab)
{
	int ** nvTab2D = malloc((Tab2D[0][0]+2)*sizeof(int*));
	for(int i=0;i<Tab2D[0][0]+1;i++)
	{
		nvTab2D[i] = Tab2D[i];
	}
	nvTab2D[Tab2D[0][0]+1] = tab;
	nvTab2D[0][0]+=1;
	return nvTab2D;
}
//------------------------------------------------------------------------------
int** genTab2D()
{
	int ** nvTab2D = malloc(sizeof(int*));
	nvTab2D[0]     = malloc(sizeof(int ));
	nvTab2D[0][0] = 0;
	return nvTab2D;
}
//------------------------------------------------------------------------------
void supprTab2D(int** Tab2D)
{
	for(int i=Tab2D[0][0];i>=0;i--)
	{
		free(Tab2D[i]);
	}
	free(Tab2D);
}
//------------------------------------------------------------------------------
void printTab2D(int** Tab2D,int taillePetitTab)
{
	int taille = Tab2D[0][0];
	printf("[");
	printf("[%d],",Tab2D[0][0]);
	for(int i=1;i<taille+1;i++)
	{
		printf("[");
		for(int j=0;j<taillePetitTab;j++) printf("%d,",Tab2D[i][j]);
		printf("\b],");
	}
	printf("\b]\n");
}
//Fonctions qui retourne la liste des cases où l'on a le droit d'aller.
//Sous forme d'un tableau de tuple : [[depart,arrivé]]
int** prioMouvement(Case* Damier, int equipe)
{
	//indique si précédemment on a déjà détecté un pion mangeable
	int PasDePionMangeable = TRUE;
	int tailleMaxChemin = 0;
	int** PionBougeable = genTab2D();

	for(int coordP=0;coordP<50;coordP++)
	{
		Case pion = Damier[coordP];
		if(pion.equipe != equipe) continue;
		int* direct = direction(coordP);

		for(int i=0;i<4;i++)
		{
			int voisin = coordP + direct[i];
			int* directVoisin = direction(voisin);

			if(Damier[voisin].equipe == ennemie(pion) && Damier[voisin+directVoisin[i]].equipe == CASE)
			{
				if (PasDePionMangeable)
				{
					PasDePionMangeable = FALSE;
					//On réinitialise l'ancien tableau de pion bougeable si c'est le premier enemie mangeable que l'on détecte.
					supprTab2D(PionBougeable);
					PionBougeable = genTab2D();
				}
				int* chemin = exploreCheminEnnemie(Damier,0,coordP,pion.equipe);
				if(tailleMaxChemin == chemin[0])
				{
					//on rentre chaque couple de déplacement dans le tableau
					//ex : depuis la case 27, le pion peux manger les pions en 21 et 22,
					//on ajoute alors : [27,16] et [27,18] dans PionBougeable.
					for(int j=1;j<6;j++)
					{
					    if(chemin[j]!=-1)
						{
							int* tmp = malloc(2*sizeof(int));
							tmp[0] = coordP;
							tmp[1] = chemin[j];
							PionBougeable = ajoutTab2D(PionBougeable,tmp);
						}
					}
					//On a trouvé un pion mangeable, grace à exploreCheminEnnemie()
					//On peut passer au pion suivant dans le Damier d'où le "break"
					break;
				}
				else if(tailleMaxChemin < chemin[0])
				{
					tailleMaxChemin = chemin[0];
					//on réinitialise pour mettre les chemins les plus uniquement
					supprTab2D(PionBougeable);
					PionBougeable = genTab2D();
					for(int j=1;j<6;j++)
					{
					    if(chemin[j]!=-1)
						{
							int* tmp = malloc(2*sizeof(int));
							tmp[0] = coordP;
							tmp[1] = chemin[j];
							PionBougeable = ajoutTab2D(PionBougeable,tmp);
						}
					}
					//On a trouvé un pion mangeable, grace à exploreCheminEnnemie()
					//On peut passer au pion suivant dans le Damier d'où le "break"
					break;
				}
			}
			else if(PasDePionMangeable)
			{
				//Déplacement basique pour équipe J1
				if(equipe == J1 && (i==0 || i==1) && Damier[voisin].equipe==CASE)
				{
					//ajout de [coordP,voisin] dans PionBougeable
					int* tmp = malloc(sizeof(int)*2);
					tmp[0]=coordP;
					tmp[1]=voisin;
					PionBougeable = ajoutTab2D(PionBougeable,tmp);

				}
				//Déplacement basique pour équipe J2
				else if(equipe == J2 && (i==2 || i==3) && Damier[voisin].equipe==CASE)
				{
					int* tmp = malloc(sizeof(int)*2);
					tmp[0]=coordP;
					tmp[1]=voisin;
					PionBougeable = ajoutTab2D(PionBougeable,tmp);

				}
			}
		}
	}
	return PionBougeable;
}

//------------------------------------------------------------------------------
int* exploreCheminEnnemie(Case* DamierR,int compt,int coordP,int equipe)
{
	//int nbCheminEg = 0;
	int test = TRUE;
	Case pion = DamierR[coordP];
	//On récupère les mouvements possibles pour le pion actuel
	int* direct = direction(coordP);
	int* cheminMax = calloc(5,sizeof(int));
	cheminMax[0] = 0;
	for(int i=1;i<6;i++) cheminMax[i] = -1;
	pion.equipe = equipe;

	//Recherche de voisins mangeable autour du pion actuel en coordP.
	for(int i=0;i<4;i++)
	{
		//On prend un voisin de coorP
		int voisin = coordP + direct[i];
		//On recupère les mouvements qu'ils a le droit de faire.
		int * directVoisin = direction(voisin);
		//printf("coordP %d et voisin regardé : %d \n", coordP,voisin);

		//On regarde si le pion dans la direction i est ennemie et si la case dérriére est prenable
		if(DamierR[voisin].equipe == ennemie(pion)&& DamierR[voisin+directVoisin[i]].equipe == CASE)
		{
			//On verifie que le pion n'a pas déjà été "sauté" dans la sequence
			if(DamierR[voisin].etat)
			{
				//printf("voisin : %d\n", voisin);
				test = FALSE;
				//On marque toutes les cases que nous sommes en train de traverser
				//Pour ne plus les considérer après dans le parcours du damier
				DamierR[voisin].etat = FALSE;
				DamierR[coordP].equipe = CASE;
				DamierR[voisin+directVoisin[i]].equipe = equipe;
				//On récupère le plus long chemin possible à partir de la case
				//où attéris le pion après avoir mangé (en voisin+directVoisin[i])
				int * chemin = exploreCheminEnnemie(DamierR,compt+1,voisin+directVoisin[i],equipe);
				//On récupère le plus long chemin entre le plus long de ceux trouvé auparavant
				//et celui trouvé tout de suite.
				if (cheminMax[0] < chemin[0])
				{
					cheminMax[0] = chemin[0];
					cheminMax[i+1] = voisin+directVoisin[i];
					free(chemin);
				}
				else if (cheminMax[0] == chemin[0])
				{
					cheminMax[i+1] = voisin+directVoisin[i];
					free(chemin);
				}
				else
				{
					cheminMax[i+1] = -1;
				}
				//On démarque les cases que l'on viens de traverser
				DamierR[voisin].etat = TRUE;
				DamierR[voisin+directVoisin[i]].equipe = CASE;
				DamierR[coordP].equipe = equipe;

			}
		}
	}
	//Si aucun des voisins autour du pion n'est mangeable :
	//on est arrivé au bout du chemin de pions ennemie mangeables
	if (test)
	{
		//On crée un tableau qui contiendra la succession de case vides
		//où l'on attérrira à chaque saut. La première case du tableau contient
		//n-1 où n est la taille du tableau.
		int* chemin = malloc(5*sizeof(int));
		chemin[0] = compt;
		for (int i=1;i<5;i++) chemin[i]=-1;
		//on doit retourner un int ** donc je retourne l'adresse de l'adresse du tableau ? : Oui pour le cas des chemins égaux (DamierType2)
		return chemin;
	}
	return cheminMax;
}

//==============================================================================
//fonctions pour le reseau
//retourne la
char * envoie(int idClient, char * message)
{
	char* message_retour = malloc(sizeof(char));

	//Envoi message vers le serveur
	if( send(idClient , message , strlen(message) , 0) < 0)
	{
		fprintf(stderr,"Echec envoi\n");
		close(idClient);
		return "msgError";
	}

	//Reception message du serveur
	if( recv(idClient , message_retour , MAX_BUFFER , 0) < 0)
	{
		fprintf(stderr,"Echec reception\n");
		return "msgError";
	}

	return message_retour;
}

char* authentification(int idClient)
{

	char message_procedure[MAX_BUFFER] = "";
	char message_authen[MAX_BUFFER] = "";
	strcat(message_procedure,"SYS-20");
	strcpy(message_authen,envoie(idClient, message_procedure));

	if(strcmp(message_authen,"authenOui") == 0)
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
						printf("Rentrez votre pseudo pour le compte (max 20 caractères): ");
						scanf("%s",pseudo);

						if(strcmp(pseudo,"-1") == 0)
						{
							retour = TRUE;
							break;
						}

						char message_compte [MAX_BUFFER] = "";
							char message_retour [MAX_BUFFER] = "";
						strcat(message_compte,"SYS-200-");
						strcat(message_compte,pseudo);
						strcpy(message_retour,envoie(idClient,message_compte)); // retourne msg = "erreurPseudo" ou "succes"

						if(strcmp(message_retour,"succes") == 0) break;
						else if(strcmp(message_retour,"erreurPseudo") == 0)
						{
							printf("\nLe pseudo '%s' n'existe pas, réessayez\n"
									"ou tapez '0' pour retourner à l'étape précédente\n",pseudo);
						}
					}
					break;
				case 1:
					//Créer compte
					while(1)
					{
						printf("Rentrez votre pseudo pour le compte (max 20 caractères): ");
						scanf("%s",pseudo);

						if(strcmp(pseudo,"0") == 0)
						{
							retour = TRUE;
							break;
						}

						char message_compte [MAX_BUFFER] = "";
						char message_retour [MAX_BUFFER] = "";
						strcat(message_compte,"SYS-201-");
						strcat(message_compte,pseudo);
						strcpy(message_retour,envoie(idClient,message_compte)); // retourne msg = "erreurPseudo" ou "succes"

						if(strcmp(message_retour,"succes") == 0) break;
						else if(strcmp(message_retour,"erreurPseudo") == 0)
						{
							printf("\nLe pseudo '%s' n'existe pas, réessayez\n"
									"ou tapez '0' pour retourner à l'étape précédente\n",pseudo);
						}
					}
					break;

				case 2:
					//compte invité*
					//char message_compte[MAX_BUFFER] = "";
					//strcat(message_compte,"SYS-202");
					pseudo = envoie(idClient,"SYS-202"); //retourne guest#### ex: guest2546
					break;
				default:
					break;
			}
		}
		return pseudo;
	}
	return "errorAuthentification";
}


char* rejoindre(int idClient){
	//Envoie du message pour obtenir liste des parties à rejoindre;

	//Message interpreté côté serveur;
	char messServeur[] 				 = "SYS-2210";
	//Message stockant le retour serveur;
	char* msgRecu = malloc(sizeof(char));

	int test = TRUE;
	//Retour de la forme 0-joueur-1-joueur.....
	strcpy(msgRecu,envoie(idClient, messServeur));
	if(!strcmp(msgRecu,"msgError"))
		return msgRecu;
	printf("liste partie dispo%s\n",msgRecu);
	//Permet d'avoir une copie du message retour;
	//Permettra d'obtenir l'identifiant du joueur 1 :)
	char message_sauv[MAX_BUFFER] = "";
	char* pseudoJ1 = malloc(sizeof(char));
	strcpy(message_sauv, msgRecu);

	//On continue la fonction s'il n'y a pas de message d'erreur.
	//Sinon on le retourne :)
	if(strcmp(msgRecu,"msgError") != 0)
	{
		int nbPartie = 0;
		printf("Veuillez choisir quelle partie vous voulez rejoindre :\n");
		char * joliePrint = strtok(msgRecu, "-");
		while(joliePrint != NULL)
		{
			printf("Partie n°%d : ", nbPartie);
			printf("Jouer avec le joueur : %s\n", joliePrint);
			joliePrint = strtok(NULL, "-");
			nbPartie ++;
		}
		//On compte une fois de trop, donc on décrémente;
		nbPartie --;
		//Attente de la réponse,
		char partie;
		int cmpRep  = 5;
		scanf("%s", &partie);
		while((partie < 0 || partie > nbPartie) && (cmpRep >= 0))
		{
			printf("Veuillez mettre une instruction valide,"
			"il vous reste %d essaie(s) avant d'être éjecté du jeu.\n", cmpRep);
			cmpRep --;
		}
		if(cmpRep >= 0)
		{
			//Message interpreté côté serveur;
			char * messServeur = "SYS-2211-";

			//Récupération du joueur1 de la partie choisie;
			char * chercheJoueur = strtok(message_sauv, "-");


			chercheJoueur = strtok(NULL, "-");

			//Forme du message à envoyer : SYS-2211-joueur1
			char message[MAX_BUFFER] = "";

			strcat(message, messServeur);
			strcat(message, chercheJoueur);

			printf("Le message est : %s\n", message);


			strcpy(pseudoJ1,envoie(idClient, message));
		}
	}
	else
	{
		test = FALSE;
		printf("Impossible de créer la partie, déconnection.\n");
	}
	if(test) return pseudoJ1;
	else
	{
		free(pseudoJ1);
		return "";
	}
}

char* regarder(int idClient){
	//Envoie du message pour obtenir liste des parties en cours;

	//Message interpreté côté serveur;
	char messServeur [] = "SYS-2220";

	printf("Le message est : %s\n",messServeur);

	//Retour de la forme 0-idClienta0/idClientb0-1-idClienta1/idClientb1.....
	char message_reception [MAX_BUFFER] = "";
	char message_sauv      [MAX_BUFFER] = "";
	strcpy(message_reception,envoie(idClient,messServeur));
	strcpy(message_sauv,message_reception);

	if(strcmp(message_reception,"msgError") != 0)
	{
		int nbPartie = 0;
		printf("Veuillez choisir quelle partie vous voulez rejoindre :\n");
		char * joliePrint = strtok(message_reception, "-");
		while(joliePrint != NULL)
		{
			printf("Partie n°%d : ", nbPartie);
			printf("Jouer avec le joueur : %s\n", joliePrint);
			joliePrint = strtok(NULL, "-");
			nbPartie ++;
		}
		//On compte une fois de trop, donc on décrémente;
		nbPartie --;
		//Attente de la réponse,
		int partie = 0;
		int cmpRep = 5;
		scanf("%d", &partie);
		while((partie < 0 || partie > nbPartie) && (cmpRep >= 0))
		{
			printf("Veuillez mettre une instruction valide,"
			"il vous reste %d essaie(s) avant d'être éjecté du jeu.\n", cmpRep);
			scanf("%d", &partie);
			cmpRep --;
		}
		if(cmpRep >= 0)
		{
			//Message interpreté côté serveur;
			char message_serveur [MAX_BUFFER] = "SYS-2221-";
			//Obtention du nom du joueur adverse choisie;
			char * chercheJoueur = strtok(message_sauv, "-");


			chercheJoueur = strtok(NULL, "-");

			//Forme du message à envoyer : SYS-2221-joueur1
			char * message = malloc(MAX_BUFFER * sizeof(char));

			strcat(message, messServeur);
			strcat(message, chercheJoueur);

			printf("Le message est : %s\n", message);

			char message_recu[MAX_BUFFER] = "";
			strcpy(message_recu,envoie(idClient, message));
			// OSKOUR, FAUT FAIRE UNE BOUCLE POUR OBTENIR LA GRILLE À CHAQUE COUP !!!!!!!!
		}
	return 	"0";
	}
}

char* optionGame(int idClient)
{
	printf("Vous voulez jouer, très bien :\n");
	printf("Que voulez vous faire ?\n");
	printf("0.Créer une nouvelle partie,\n");
	printf("1.Rejoindre une partie,\n");
	printf("2.Regarder une partie en cours,\n");
	printf("3.Quitter le jeu.\n");

	printf("\nOption : ");
	int reponse = -1;
	int cmpRep = 5;
	int test = TRUE;
	char* pseudo = malloc(MAX_BUFFER*sizeof(char));
	scanf("%d", &reponse);
	while((reponse < 0 || reponse > 3) && (cmpRep >= 0))
	{
		printf("Veuillez mettre une instruction valide, "
		"il vous reste %d essaie(s) avant d'être éjecté du jeu.\n", cmpRep);
		scanf("%d", &reponse);
		cmpRep --;
	}

	//Definition d'une chaine permettant de récuperer le retour des foctions intermédiares.
	switch (reponse)
	{
		//Créer une nouvelle partie
		case 0:
			strcpy(pseudo,envoie(idClient,"SYS-220"));
			if(!strcmp(pseudo,"msgError"))
			{
				test = FALSE;
				printf("Il y déjà trop de parties en cours, essayez d'en rejoindre une \nou regardez en une en attendant \n");
			}
			//msg = succes si la partie est bien créée
			break;
		//Rejoindre une partie
		case 1:
			strcpy(pseudo,rejoindre(idClient));
			if(!strcmp(pseudo,"msgError"))
				test=FALSE;

			break;
		//Regarder une partie
		case 2:
			regarder(idClient);
			break;
		//Fin du jeu
		default:
			break;
	}

	if(test) return pseudo;
	else
	{
		printf("DEBUUUUUUG\n");
		free(pseudo);
		return "msgError";
	}
}

/*
	creationGame   -> idClient-SYS-220
	rejoindreLobby -> idClient-SYS-221
		rejoindreGame ->
	regarderLobby  -> idClient-SYS-222
		regarderGame  ->
	quitter -> Requête Identique à Déco
*/

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
	//Trouver un pseudo existant dans le fichier
	if(mode == 0)
	{
		strcat(modifCompte,"-");
		strcat(modifCompte,compte);
		while(fscanf(fichier,"%s\n",buff) != -1)
		{
			//Si on détecte le nom dans la base de donnée
			if(buff[0]=='-' && !strcmp(modifCompte,buff))
			{
				printf("buffmode0 %s\n",buff);
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
			ajoutCompte(fichier,compte);
			free(fichier);
			return 1;
		}
	}
	else if(mode == 2)
	{
		strcat(modifCompte,"+");
		strcat(modifCompte,compte);
		//Deconnexion
		while(fscanf(fichier,"%s\n",buff) != -1)
		{
			//Si on détecte le nom dans la base de donnée
			if(buff[0]=='+' && !strcmp(modifCompte,buff))
			{
				printf("buffmode2 %s\n",buff);

				fseek(fichier,-strlen(compte)-2,SEEK_CUR);
				decoReco(fichier,ftell(fichier),'-');
				free(fichier);
				return 1;
			}
		}
	}
	else
	{
		fprintf(stderr,"Erreur: mode invalide pour fonction utiliserCompte\n");
	}
	free(fichier);
	return 0;
}
//Avoir indice coordP d'une case dans Damier à partir de ses coordonnées [x,y]
int caseAvecCoord(int x,int y)
{
	if((x%2 == 0 && y%2 == 1) || (x%2 == 1 && y%2 == 0))
		return (y*5)+(x/2);
	else return -1;
}
//Avoir coordonnée [x,y] d'une case à partir de son indice coordP dans Damier
int* coordAvecCase(int coordP)
{
	//tableau de retour de forme : [x,y]
	int* tmp = malloc(2*sizeof(int));
	//Si on est sur une ligne paire
	if (((coordP-coordP%5)/5)%2 == 0)
		tmp[0] = (coordP*2+1)%10;
	//Si la ligne est impaire
	else
		tmp[0] = (coordP*2)%10;
	tmp[1] = (coordP-coordP%5)/5;
	return tmp;
}
int* entreeJoueur(Case* Damier,int** MouvLegaux)
{
	system("clear");
	prettyPrintDamier(Damier);
	printf("\nVoici les coups possibles :\n______________________\n");

	for(int i=1;i<MouvLegaux[0][0]+1;i++)
	{
		int* coordXYDep = coordAvecCase(MouvLegaux[i][0]);
		int* coordXYArr = coordAvecCase(MouvLegaux[i][1]);
		printf("%d (%d,%d) --> (%d,%d)\n",i-1,coordXYDep[0],coordXYDep[1],coordXYArr[0],coordXYArr[1]);
	}
	printf("-1 Quitter la partie (abandon)\n");

	int choix = 1000;
	int test = FALSE;
	while(1)
	{
		if(choix>=-1 && choix<MouvLegaux[0][0]) break;
		if(choix != 1000 && test) printf("Le coup n° %d n'est pas disponible\n",choix);
		test = TRUE;
		printf("\nNuméro du coup à jouer :\n");
		scanf("%d",&choix);
	}
	//printf("le choix est %d\n",choix);

	return MouvLegaux[choix+1];
}
char * transformCoupleToChar(Case * Damier,int Couple[2])
{
    //Sert de chaine de charactère de retour
    char * chaine_char = malloc(6*sizeof(char));
    //Sert de chaine de charctère pour les nombres
    char v1[3]="";
    char v2[3]="";

    //Transforme un entier en charactère
    sprintf(v1,"%d",Couple[0]);
    sprintf(v2,"%d",Couple[1]);

    strcpy(chaine_char,v1);
    strcat(chaine_char,"-");
    strcat(chaine_char,v2);

    return chaine_char;
}

char * transformDamierToChar(Case * Damier)
{
    char * strDamier   = malloc(101 * sizeof(char));
    char * caseVide    = "0";
    char * equipe1     = "1";
    char * equipe2     = "2";

    int i = 0;
    if(Damier[i].equipe == 1)
    {
        strcpy(strDamier, equipe1);
        strcat(strDamier, "-");
    }
    else if(Damier[i].equipe == 2)
    {
        strcpy(strDamier, equipe2);
        strcat(strDamier, "-");
    }
    else
    {
        strcpy(strDamier, caseVide);
        strcat(strDamier, "-");
    }

    for(i = 1; i<50; i++)
    {
        if(Damier[i].equipe == 1)
        {
            strcat(strDamier,equipe1);
            strcat(strDamier, "-");
        }
        else if(Damier[i].equipe == 2)
        {
            strcat(strDamier,equipe2);
            strcat(strDamier, "-");
        }
        else
        {
            strcat(strDamier,caseVide);
            strcat(strDamier, "-");
        }
    }

    return strDamier;
}

Case * transformCharToDamier(char * ChaineChar)
{
    Case * Damier = genJeu();
    int i = 0;
    char separateur[] = "-";
    char * ChaineProvisoire = strtok(ChaineChar, separateur);

    while(ChaineProvisoire != NULL)
    {
        Damier[i].equipe = atoi(ChaineProvisoire);
        ChaineProvisoire = strtok(NULL, separateur);
        i++;
    }

    return Damier;
}

int * transformCharToCouple(char * ChaineChar)
{
    int * Couple = malloc(2 * sizeof(int));
    char * cpyChaine = malloc(6* sizeof(char));
    strcpy(cpyChaine, ChaineChar);
    char * v1;
    char * v2;

    //Le séparateur '-'
    v1 = strtok(cpyChaine,"-");
    v2 = strtok(NULL,"");

    //On obtient les 2 valeurs en Char
    //Passage des valeurs en int
    Couple[0] = atoi(v1);
    Couple[1] = atoi(v2);

    return Couple;
}
//==============================================================================
//Gestion partie
Partie* genListePartie()
{
	Partie* ListePartie = malloc(MAX_PARTIE*sizeof(struct Partie));
	for(int i=0;i<MAX_PARTIE;i++)
	{
		ListePartie[i].Damier = genJeu();
		ListePartie[i].tourActu = 0;
		ListePartie[i].tourPrec = 0;
		ListePartie[i].idJ1	 = 0;
		ListePartie[i].idJ2	= 0;
		ListePartie[i].userJ1 = malloc(21*sizeof(char));
		ListePartie[i].userJ2 = malloc(21*sizeof(char));
	}
	return ListePartie;
}
//triplette de recuperation des index dans ListePartie=========
int indexCreerPartie(Partie* ListePartie)
{
	for(int i=0;i<MAX_PARTIE;i++)
	{
		if(ListePartie[i].idJ1 == 0)
		return i;
	}
	return -1;
}
//retourne liste des slots dispo pour rejoindre une partie
char* listePartieRejoindre(Partie* ListePartie)
{
	char* liste = malloc(MAX_BUFFER*sizeof(char));
	strcpy(liste,"");
	for(int i=0;i<MAX_PARTIE;i++)
	{
		printf("i : %d tour : %d %d\n",i,ListePartie[i].tourActu,ListePartie[i].idJ1);

		if(ListePartie[i].idJ1 != 0 && ListePartie[i].idJ2 == 0)
		{
			printf("YOUPI TAS REUSSI \n");

			strcat(liste,ListePartie[i].userJ1);
			strcat(liste,"-");
		}
	}
	return liste;
	//Pas de partie dispo.
}
//Rejoindre partie complètes pour les regarder
char* listePartieRegarder(Partie* ListePartie)
{
	char* liste = malloc(MAX_BUFFER*sizeof(char));
	strcpy(liste,"");
	for(int i=0;i<MAX_PARTIE;i++)
	{
		printf("i : %d \n",i);

		if(ListePartie[i].idJ1 != 0 && ListePartie[i].idJ2 != 0)
		{
			strcat(liste,ListePartie[i].userJ1);
			strcat(liste,"-");
		}
	}
	//tester le retour si == "" pas de partie complètes.
	return liste;
}
int indexPartieDpPseudo(Partie* ListePartie, char* pseudo)
{
	for(int i=0;i<MAX_BUFFER;i++)
	{
	    if(!strcmp(ListePartie[i].userJ1,pseudo))
			return i;
	}
}
//Retourne le pseudo d'un guest
char* genGuest(int* numGuest)
{
	*numGuest += 1;
	char* name  = malloc(20*sizeof(char));
	char tmp[20]= "";
	strcpy(name,"Guest#");
	sprintf(tmp, "%d",*numGuest);
	strcat(name,tmp);
	return name;
}

//==============================================================================
