#include "main.c"

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
	while(1)
	{
		if(choix>=-1 && choix<MouvLegaux[0][0]) break;
		if(choix != 1000) printf("Le coup n° %d n'est pas disponible\n",choix);
		printf("\nNuméro du coup à jouer :\n");
		scanf("%d",&choix);
	}
	//printf("le choix est %d\n",choix);

	return MouvLegaux[choix+1];
}

int main()
{
	printf("Connexion au serveur\n");
	printf("Choisir son ID / Si on est un invité\n");
	printf("attente du serv pour l'autre joueur ou le damier\n");

	printf("Recevoir Damier et l'afficher\n");
	Case* Damier=genJeu(50);
	//damierType2(Damier,50);
	prettyPrintDamier(Damier);
	printf("Recevoir la liste de coups légaux et attendre l'entrée joueur\n");
	//printf("case en [6,7] %d\n",caseAvecCoord(6,7));

	int** MouvLegaux = prioMouvement(Damier,J1);
	printTab2D(MouvLegaux,2);
	int * tmp = entreeJoueur(Damier,MouvLegaux);
	printf("[%d,%d]\n",tmp[0],tmp[1]);

	return 0;
}
