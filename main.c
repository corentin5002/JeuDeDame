#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

#define J1 1
#define J2 2
#define CASE 0
#define TRUE  1
#define FALSE 0
//==============================================================================
//structure d'une case du Damier------------------------------------------------
typedef struct Case Case;
struct Case
{
	int dame  ;
	int equipe;
	int etat;
};
//==============================================================================
//outils
Case * genJeu			(int tailleDamier);
void bougerPiece		(Case* Damier,int cDepart,int cArrivee);
void prettyPrint		(Case* Damier);
void prettyPrintDamier	(Case* Damier);
void setCase			(Case* Damier,int coord,Case cNvl);
int  ennemie			(Case pion);
void damierType1		(Case* Damier,int tailleDamier);
int* getDirection		(int coordP);
Case* cpyDamier			(Case* Damier);


//==============================================================================
int** exploreCheminEnnemie(Case* DamierR,int compt,int coordP,int equipe)
void siEnnemieVoisin(Case* Damier,int coordP);
//==============================================================================

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
int allie(Case pion)
{
	return (pion.equipe == J1) ? J2 : J1;
}
//------------------------------------------------------------------------------
Case* cpyDamier(Case* Damier)
{
	Case * DamierR = malloc(50*sizeof(Case));
	memcpy(DamierR,Damier,50);
	for(int i=0;i<50;i++) DamierR[i] = Damier[i];
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
    else if (numligne == 0)
    {
        int tmp[4]={0,0,6,5};
        for (int i = 0; i < 4; i++) direction[i] = tmp[i];
    }
    //Ligne du Bas
    else if (numligne == 5)
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

int * prioMouvement(Case* Damier, int coordP)
{
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
    }
}
//Cas de si on a au moins un jeton enemie en voisin
void siEnnemieVoisin(Case* Damier,int coordP)
{
	Case pion = Damier[coordP];

	//direction est le "patron" des directions autour du pion en coordP
	int* direction = getDirection(coordP);

	//code de recherche
	int * arriveeCaseMange = malloc(sizeof(int)*4);
	int i;
	for (i = 0; i<4 ; i++)
	{
		//Initialisation de la liste des voisin mangeables
		arriveeCaseMange[i]=0;
		int voisin = coordP + direction[i];
		int * directionVoisin = getDirection(voisin);
		//On regarde si le pion dans la direction i est ennemie et si la case dérriére est prenable
		if(Damier[voisin].equipe == ennemie(pion) && Damier[voisin+directionVoisin[i]].equipe == 0)
		{
			printf("Le pion en %d est prenable\n",voisin);
			arriveeCaseMange[i] = voisin+directionVoisin[i];
			Damier[voisin].etat = FALSE;
			//Recherche recursive qui ressort le max de chaque chemin
			int** chemins = exploreCheminEnnemie(Damier,1,voisin+directionVoisin[i],pion.equipe);

		}
	}

	//Si aucun voisin n'est mangeable.

	//Sinon :
}
//------------------------------------------------------------------------------
int** exploreCheminEnnemie(Case* DamierR,int compt,int coordP,int equipe)
{

	int test = FALSE;
	int* direction = getDirection(coordP);
	Case pion = DamierR[coordP];
	pion.equipe = equipe;

	for(int i=0;i<4;i++)
	{
		int voisin = coordP + direction[i];
		int * directionVoisin = getDirection(voisin);
		printf("coordP %d et voisin regardé : %d \n", coordP,voisin);
		//On regarde si le pion dans la direction i est ennemie et si la case dérriére est prenable
		if(DamierR[voisin].equipe == ennemie(pion)&& DamierR[voisin+directionVoisin[i]].equipe == 0)
		{
			printf("voisin : %d\n", voisin);
			test = TRUE;
		}
	}
	if (test)
	{
		int* chemin = malloc((compt+1)*sizeof(int));
		chemin[0] = compt;
		//on doit retourner un int ** donc je retourne l'adresse de l'adresse du tableau ?
		pion.equipe = CASE;
		return chemin;
	}
}

//------------------------------------------------------------------------------

int main()
{
	//Case test = {FALSE,J1};
    Case *Damier = genJeu(50);
    bougerPiece(Damier,17,22);
	damierType1(Damier,50);
	siEnnemieVoisin(Damier,27);
    return 0;
}
