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
    printf("| ");
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
        printf("%d ",Damier[i].equipe);
        if (i%5 == 4) printf("|\n| ");
    }
    printf("\b\b \n");
    return Damier;
}
//------------------------------------------------------------------------------
void bougerPiece(Case* Damier,int cDepart,int cArrivee)
{
    Damier[cArrivee].equipe = Damier[cDepart].equipe;
    Damier[cDepart].equipe = 0;
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
	printf("\n_______________________\n");
    printf("| ");
    int i;
    for(i=0;i<50;i++)
    {
        //on extrait le numéro de la ligne
        int numL = (i-i%5)/5;
        //Si la ligne est paire
        if (numL%2 == 0) printf("  %d ",Damier[i].equipe);
        //Si la ligne est impaire
        else printf("%d   ",Damier[i].equipe);
        if (i%5 == 4) printf("|\n| ");
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

	printf("     Damier actuel\n");
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


	printf("     Damier actuel\n");
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


	printf("     Damier actuel\n");
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
int* getDirection(int coordP)
{
	//Determine si on est sur ligne paire ou impaire
	int numLigne = (coordP-coordP%5)/5;
	int* direction = malloc(4*sizeof(int));

    //Coin en Haut à droite
    if (coordP == 4)
    {
        int tmp[4]={0,0,0,5};
        for (int i = 0; i < 4; i++) direction[i] = tmp[i];
    }
    //Coin en Bas à gauche
    else if (coordP == 45)
    {
        int tmp[4]={0,-5,0,0};
        for (int i = 0; i < 4; i++) direction[i] = tmp[i];
    }
    //Ligne du Haut
    else if (numLigne == 0)
    {
        int tmp[4]={0,0,6,5};
        for (int i = 0; i < 4; i++) direction[i] = tmp[i];
    }
    //Ligne du Bas
    else if (numLigne == 5)
    {
        int tmp[4]={-6,-5,0,0};
        for (int i = 0; i < 4; i++) direction[i] = tmp[i];
    }
    //Colonne de Droite
    else if (coordP % 10 == 4)
    {
        //Case sur les lignes paires
        if (numLigne%2 == 0)
        {
            int tmp[4]={-5,0,0,5};
            for (int i = 0; i < 4; i++) direction[i] = tmp[i];
        }
        //Case sur les lignes impaires
        else
        {
            int tmp[4]={-6,0,0,4};
            for (int i = 0; i < 4; i++) direction[i] = tmp[i];
        }
    }
    //Colonne de Gauche
    else if (coordP % 10 == 5)
    {
        //Case sur les lignes paires
        if (numLigne%2 == 0)
        {
            int tmp[4]={0,-4,6,0};
            for (int i = 0; i < 4; i++) direction[i] = tmp[i];
        }
        //Case sur les lignes impaires
        else
        {
            int tmp[4]={0,-5,5,0};
            for (int i = 0; i < 4; i++) direction[i] = tmp[i];
        }
    }
    //Case sur les lignes paires
	else if (numLigne%2 == 0)
	{
		int tmp[4]={-5,-4,6,5};
		for (int i = 0; i < 4; i++) direction[i] = tmp[i];
	}
    //Case sur les lignes impaires
	else
	{
		int tmp[4]={-6,-5,5,4};
		for (int i = 0; i < 4; i++) direction[i] = tmp[i];

	}

	return direction;
}
//------------------------------------------------------------------------------
//Fonctions pour détecter les mouvements des pions

int * prioMouvement(Case* Damier, int equipe)
{/*
    Case piece = Damier[coordP];

    if (siEnnemieVoisin(Damier, coordP) != NULL)
    {
        return siEnnemieVoisin(Damier, coordP);
    }
    else if (siAucunMouv(Damier, coordP) != NULL)
    {
        return {-1};
    }
    else
    {
        return
    }*/
}

//------------------------------------------------------------------------------
int* exploreCheminEnnemie(Case* DamierR,int compt,int coordP,int equipe)
{
	//int nbCheminEg = 0;
	int test = TRUE;
	Case pion = DamierR[coordP];
	//On récupère les mouvements possibles pour le pion actuel
	int* direction = getDirection(coordP);
	int* cheminMax = malloc(5*sizeof(int));
	cheminMax[0] = 0;
	pion.equipe = equipe;

	//Recherche de voisins mangeable autour du pion actuel en coordP.
	for(int i=0;i<4;i++)
	{
		//On prend un voisin de coorP
		int voisin = coordP + direction[i];
		//On recupère les mouvements qu'ils a le droit de faire.
		int * directVoisin = getDirection(voisin);
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
				//printf("compt : %d chemin[compt] : %d\n",compt,chemin[compt]);
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

					//actu  [n, 16,-1,-1,-1]
					//old [n, 5,7,-1,-1]
				}
				else cheminMax[i] = -1;
				//On démarque les cases que l'on viens de traverser
				DamierR[voisin].etat = TRUE;
				DamierR[voisin+directVoisin[i]].equipe = CASE;
				DamierR[coordP].equipe = equipe;
				printf("\n%d [",i);
				for(int j = 0;j<5;j++) printf(" %d,", cheminMax[j]);
				printf("\b]\n");
			}
		}
	}
	//Si aucun des voisins autour du pion n'est mangeable :
	//on est arrivé au bout du chemin de pions ennemie mangeables
	if (test)
	{
		printf("DEBUG2 compt: %d\n",compt );
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

int main()
{
	//Case test = {FALSE,J1};
    Case* Damier = genJeu(50);
	int* chemin;
    bougerPiece(Damier,17,22);
	damierType3(Damier,50);
	//siEnnemieVoisin(Damier,27);
	chemin = exploreCheminEnnemie(Damier,0,44,Damier[44].equipe);

	for(int i=0;i<5;i++ )
	{
		printf("%d ,",chemin[i]);
	}
	printf("\b \n");
    return 0;
}
