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
};
//==============================================================================
Case * genJeu			(int tailleDamier);
void bougerPiece		(Case* Damier,int cDepart,int cArrivee);
void prettyPrint		(Case* Damier);
void prettyPrintDamier	(Case* Damier);
void setCase			(Case* Damier,int coord,Case cNvl);
void damierType1		(Case* Damier,int tailleDamier);

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
	printf("_______________________\n");
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

	for (int i=0; i<tailleDamier; i++)
	{
		setCase(Damier,i,caseTest);
	}
	caseTest.equipe = J1;
	setCase(Damier,26,caseTest);
	caseTest.equipe = J2;
	setCase(Damier,21,caseTest);
	setCase(Damier,20,caseTest);
	setCase(Damier,10,caseTest);

	printf("     Damier actuel\n");
	prettyPrintDamier(Damier);
}
//------------------------------------------------------------------------------
void setCase(Case* Damier,int coord,Case cNvl)
{
    Damier[coord].equipe = cNvl.equipe;
	Damier[coord].dame   = cNvl.dame;
}
//------------------------------------------------------------------------------

int main()
{
    Case *Damier = genJeu(50);
    bougerPiece(Damier,17,22);

	damierType1(Damier,50);
    return 0;
}
