#ifndef RESO_H
#define RESO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>
//=============================================================================
#define TRUE 1
#define FALSE 0

//FONCTIONS=====================================================================
//Gestion des envois entre le client et le serveur
char* triageArrivee		(char* msgRecu);
char* optionGame		(char* idClient);

//Gestion des fonctions SYS
char* connexion			();
char* deconnexion		(char* idClient);
char* authentification	(char* idClient);
char* creationPartie	(char* idClient);
char* jeuPartie			(char* idClient, int equipe);
char* rejoindreSession	(char* idClient);
char* rejoindrePartie	(char* idPartie, int partie);
char* regarderSession	(char* idClient);
char* regarderPartie	(char* idPartie);

//Manipulation du fichier "compte"
//Ajout d'une chaine de caractère à la fin du fichier.
void ajoutCompte		(FILE* fichier,char* chaine);
void decoReco			(FILE* fichier,long curseur,char nvChar);
int utiliserCompte		(char* compte ,int mode);

#endif
