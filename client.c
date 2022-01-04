#include "main.c"

int caseAvecCoord(int x,int y)
{
	return (y*5)+(x/2);
}


int main()
{
	printf("Connexion au serveur\n");
	printf("Choisir son ID / Si on est un invité\n");
	printf("attente du serv pour l'autre joueur ou le damier\n");

	printf("Recevoir Damier et l'afficher\n");
	Case* Damier=genJeu(50);
	prettyPrintDamier(Damier);
	printf("Recevoir la liste de coups légaux et attendre l'entrée joueur\n");
	printf("case en [6,7] %d\n",caseAvecCoord(6,7));


	return 0;
}
