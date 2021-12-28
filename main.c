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
//------------------------------------------------------------------------------
Case * genJeu()
{
    Case * Damier = malloc(50*sizeof(Case));
    int i;
    //initialisation du Damier
    printf("| ");
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
        printf("%d ",Damier[i].equipe);
        if (i%5 == 4) printf("|\n| ");
    }
    printf("\b\b \n");
    return Damier;
}
//------------------------------------------------------------------------------
Case *bougerPiece(Case* Damier,int cDepart,int cArrivee)
{
    Damier[cArrivee].equipe = Damier[cDepart].equipe;
    Damier[cDepart].equipe = 0;
    return Damier;
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
void prettyPrint(Case* Damier)
{
    printf("| ");
    int i;
    for(i=0;i<50;i++)
    {
        printf("%d ",i);
        if (i < 10)   printf(" ");
        if (i%5 == 4) printf("|\n| ");
    }
    printf("\b\b \n");
}
//------------------------------------------------------------------------------

int main()
{
    Case *Damier = genJeu();
    Damier = bougerPiece(Damier,17,22);
    prettyPrint(Damier);
    return 0;
}
