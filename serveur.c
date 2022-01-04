#include "serveur.h"
#include "main.h"


char * tranformChar(int * Damier,int * Couple)
{
    //Sert de chaine de charactère de retour
    char * envoie = malloc(5*sizeof(char));
    //Sert de chaine de charctère pour le deuxième nombre
    char v[2];

    sprintf(v,"%d",Couple[1]);
    
    int* direct = direction(Couple[0]);
	for(int i=0;i<4;i++)
	{
		int voisin = Couple[0] + direct[i];
		int* directVoisin = direction(voisin);
		if (Couple[1] == voisin)
		{
            sprintf(envoie,"%d",Couple[0]);
            strcat(envoie,"-");
            strcat(envoie,v);
			break;
		}
		else if (Couple[1] == voisin + directVoisin[i])
        {
            sprintf(envoie,"%d",Couple[0]);
            strcat(envoie,"x");
            strcat(envoie,v);
			break;
		}
	}

    return envoie;
}

int main()
{
    return 0;
}