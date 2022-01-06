#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Ajout d'une chaine de caractère à la fin du fichier.
void ajoutCompte(FILE* fichier,char* chaine)
{
	fseek(fichier, 0, SEEK_END);
	fputc('-',fichier);
	fputs(chaine,fichier);
	fputs("\n",fichier);
	fseek(fichier, 0, SEEK_SET);
}

void decoReco(FILE* fichier,long curseur,char nvChar)
{
	fseek(fichier,curseur,SEEK_SET);
	fputc(nvChar,fichier);
	fseek(fichier, 0, SEEK_SET);
}

int utiliserCompte(char* compte,int mode)
{
	FILE* fichier = fopen("comptes","r+");
	char* buff = malloc(22*sizeof(char));
	char* modifCompte=malloc(22*sizeof(char));
	strcat(modifCompte,"-");
	strcat(modifCompte,compte);
	//Trouver un pseudo existant dans le fichier
	if(mode == 0)
	{
		while(fscanf(fichier,"%s\n",buff) != -1)
		{
			//Si on détecte le nom dans la base de donnée
			if(buff[0]=='-' && !strcmp(modifCompte,buff))
			{
				fseek(fichier,-strlen(compte)-2,SEEK_CUR);
				decoReco(fichier,ftell(fichier),'+');
				free(fichier);
				return 1;
			}
		}
	}
	//Créer un nouveau compte n'existant pas dans le fichier
	else if(mode == 1)
	{
		int test = 1;
		char* enCours= malloc(sizeof(char));
		strcat(enCours,"*");
		strcat(enCours,compte);
		while(fscanf(fichier,"%s\n",buff) != -1)
		{

			if(!strcmp(compte,buff))
			{
				//Si on détecte le nom de compte dans la BD
				test = 0;
				break;
			}
			else if(!strcmp(enCours,buff))
			{
				//Si on détecte le nom de compte dans la BD et qu'il est déjà connecté
				test = 0;
				break;
			}
		}
		//Si le nom de compte n'a pas été trouvé
		if(test)
		{
			printf("DEBUG %s\n",compte);
			ajoutCompte(fichier,compte);
			free(fichier);
			return 1;
		}
	}
	else
	{
		fprintf(stderr,"Erreur: mode invalide pour fonction utiliserCompte\n");
	}
	free(fichier);
	return 0;
}
int main()
{
	char* tmp = malloc(sizeof(char));
	strcat(tmp,"julian");
	printf("retour %d\n",utiliserCompte(tmp,0));
	return 0;
}
