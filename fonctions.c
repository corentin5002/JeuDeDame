#include "fonctions.h"

//------------------------------------------------------------------------------
//Fonction de génération d'un damier de taille 10x10
//Retourne un pointeur sur un tableau une dimension de 50 Case.
Case * genJeu(int tailleDamier)
{
	Case * Damier = malloc(tailleDamier*sizeof(Case));
	int i;
	//initialisation du Damier
	for(i=0;i<tailleDamier;i++){
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
	nvTab2D[0][0]++;
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
    char * envoie = malloc(6*sizeof(char));
    //Sert de chaine de charctère pour les nombres
    char v1[3]="";
    char v2[3]="";

    //Transforme un entier en charactère
    sprintf(v1,"%d",Couple[0]);
    sprintf(v2,"%d",Couple[1]);

    strcpy(envoie,v1);
    strcat(envoie,"-");
    strcat(envoie,v2);

    return envoie;
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
    Case * Damier = genJeu(50);
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

int main()
{
	//Case test = {FALSE,J1};
	Case* Damier = genJeu(50);
	int* chemin;
	//bougerPiece(Damier,17,22);
	damierType3(Damier,50);
	return 0;
}
