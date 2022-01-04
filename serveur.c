#include "serveur.h"
#include "main.c"

char * transformChar(Case * Damier,int Couple[2])
{
    //Sert de chaine de charactère de retour
    char * envoie = malloc(6*sizeof(char));
    //Sert de chaine de charctère pour le deuxième nombre
    char v1[3]="";
    char v2[3]="";
    

    sprintf(v1,"%d",Couple[0]);
    sprintf(v2,"%d",Couple[1]);

    int* direct = direction(Couple[0]);
	for(int i=0;i<4;i++)
	{
		int voisin = Couple[0] + direct[i];
		int* directVoisin = direction(voisin);
		if (Couple[1] == voisin)
		{
            strcpy(envoie,v1);
            strcat(envoie,"-");
            strcat(envoie,v2);
			break;
		}
		else if (Couple[1] == voisin + directVoisin[i])
        {
            strcpy(envoie,v1);
            strcat(envoie,"x");
            strcat(envoie,v2);
			break;
		}
	}

    return envoie;
}

char * transformDamier(Case * Damier)
{
    char * strDamier   = malloc(51 * sizeof(char));
    char * caseVide    = "0";
    char * equipe1     = "1";
    char * equipe2     = "2";
    
    int i = 0;
    if(Damier[i].equipe == 1)
    {
        strcpy(strDamier, equipe1);
    }
    else if(Damier[i].equipe == 2)
    {
        strcpy(strDamier, equipe2);
    }
    else
    {
        strcpy(strDamier, caseVide);
    }

    for(i = 1; i<50; i++)
    {
        if(Damier[i].equipe == 1)
        {
            strcat(strDamier,equipe1);
        }
        else if(Damier[i].equipe == 2)
        {
            strcat(strDamier,equipe2);
        }
        else
        {
            strcat(strDamier,caseVide);
        }
    }

    return strDamier;
}

int main()
{
    
    //Case test = {FALSE,J1};
	Case* Damier = genJeu(50);
	//int* chemin;
	//bougerPiece(Damier,17,22);
	damierType3(Damier,50);

    char * test;
    test = transformDamier(Damier);
    printf("La chaine contient : %s\nEt sa taille est de : %ld\n", test,strlen(test));

    free(test);

    char * test2;
    int TabTest[2];
    TabTest[0] = 27;
    TabTest[1] = 21;
    test2 = transformChar(Damier,TabTest);
    printf("La chaine contient : %s\nEt sa taille est de : %ld\n", test2,strlen(test2));

    free(test2);

    return 0;
}