#include "main.h"

/* VOIR "main.h" POUR COURTE DESCRIPTION DES FONCTIONS ET STRUCTURES */

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
				/*
				printf("\n%d [",i);
				for(int j = 0;j<5;j++) printf(" %d,", cheminMax[j]);
				printf("\b]\n");
				*/
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

//------------------------------------------------------------------------------
/*
int main()
{
	//Case test = {FALSE,J1};
	Case* Damier = genJeu(50);
	int* chemin;
	//bougerPiece(Damier,17,22);
	damierType3(Damier,50);


	return 0;
}
<<<<<<< HEAD
*/
=======
*/
>>>>>>> rangement
