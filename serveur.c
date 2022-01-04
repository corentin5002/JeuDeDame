#include "serveur.h"
#include "main.c"

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

    //On cherche quel séparateur est utilisé:

    //On test si le séparateur c'est '-'
    v1 = strtok(cpyChaine,"-");
    v2 = strtok(NULL,"");

    //On obtient les 2 valeurs en Char
    //Passage des valeurs en int
    Couple[0] = atoi(v1);
    Couple[1] = atoi(v2);
    
    return Couple;
}

int main()
{
    
    //Case test = {FALSE,J1};
	Case* Damier = genJeu(50);
	//int* chemin;
	//bougerPiece(Damier,17,22);
	damierType3(Damier,50);

    // Test de la transformation Damier -> String
    char * test;
    test = transformDamierToChar(Damier);
    printf("La chaine contient : %s\nEt sa taille est de : %ld\n", test,strlen(test));

    // Test de la transformation Couple -> String
    char * test2;
    int TabTest[2];
    TabTest[0] = 0;
    TabTest[1] = 6;
    test2 = transformCoupleToChar(Damier,TabTest);
    printf("La chaine contient : %s\nEt sa taille est de : %ld\n", test2,strlen(test2));

    // Test de la transformation String -> Damier

    Case * TestD = transformCharToDamier(test);
    prettyPrintDamier(TestD);

    printf("Testing HARD\n");

    // Test de la transformation String -> Couple
    printf("Test de la transformation String -> Couple\n");
    int * TabTest3;
    TabTest3 = transformCharToCouple(test2);

    printf("Le couple de valeur est : (%d,%d).\n",TabTest3[0], TabTest3[1]);

    free(test);    
    free(test2);
    free(TabTest3);

    return 0;
}