#ifndef JDDAME_H
#define JDDAME_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <string.h>
//=============================================================================
#define J1 1
#define J2 2
#define CASE 0
#define TRUE  1
#define FALSE 0
#define MAX_PARTIE 10
//==============================================================================
//structure d'une case du Damier------------------------------------------------
struct Case
{
	int dame  ; //Si la case contient un pion = FALSE sinon = TRUE
	int equipe; //Si la case contient un pion du J1, du J2 ou une case vide (1,2,0)
	int etat  ; //Marqueur pour les différentes fonctions.
};
typedef struct Case Case;

//Structure d'une partie côté serveur
struct Partie
{
	Case * Damier; //Damier de la partie
	int tour;	//indique qui doit joueur
	int num; //identifiant de la partie
	int j1; //contient l'idClient du joueur 1
	int j2; //idem 				  joueur 2
};
typedef struct Partie Partie;
//Structure d'entree des arguments dans le thread_create

typedef struct Args Args;
struct Args
{
	int idClient;
	Partie* Lpartie;
};
//FONCTIONS=====================================================================

//outils
//Créer le damier
Case * genJeu			();
//Set une case du damier
void setCase			(Case* Damier,int coord,Case cNvl);
//Gère le mouvement d'un pion (soit vers l'avant sur case vide, soit mange un pion)
void bougerPiece		(Case* Damier,int cDepart,int cArrivee);
//Affiche le damier dans le terminal
void prettyPrintDamier	(Case* Damier);
//Retourne l'equipe ennemie du pion
int  ennemie			(Case pion);
//Retourne un tableau de taille 4 donnant les adresses relatives des cases voisines du pion en coordP
int* direction			(int coordP);
//Retourne les coups autorisés au débuts du tour du joueur
int** prioMouvement     (Case* Damier, int equipe);
//Retourne les voisins de la case en coordP qui commencent les plus longs chemins de pièces mangées.
int* exploreCheminEnnemie(Case* DamierR,int compt,int coordP,int equipe);
//------------------------------------------------------------------------------
//outils pour les tableaux
//Crée un tableau 2D d'entier de forme [[tailleTab2D],[caseDeDepart,caseArrivee],...]
int** genTab2D          ();
//Ajoute un tableau de int à la fin du tableau 2D (et incrémente sa taille stockée en Tab2D[0][0])
int** ajoutTab2D        (int** Tab2D,int* tab);

//Libère la mémoire prise par un tableau 2D
void supprTab2D         (int** Tab2D);
//Affiche un tableau d'entier 2D #DEBUG
void printTab2D			(int** Tab2D,int taillePetitTab);


//Damiers type et fonctions qui vont partir à la poubelle
void damierType1        (Case * Damier,int tailleDamier);
void damierType2        (Case * Damier,int tailleDamier);
void damierType3        (Case * Damier,int tailleDamier);
void damierType4        (Case * Damier,int tailleDamier);
void prettyPrint		(Case* Damier);
void prettyPrintPassage (Case* Damier);
//Copie le damier
Case* cpyDamier			(Case* Damier);
//==============================================================================
//Fonction pour le reseau
//Gestion des envois entre le client et le serveur
char* triageArrivee		(char* msgRecu);
char* optionGame		(char* idClient);

//Gestion des fonctions SYS
char* connexion			();
char* deconnexion		(char* idClient);
char* authentification	(char* idClient);
char* attenteJoueur 	(char* idClient);
char* jeuPartie			(char* idClient, int equipe);
char* rejoindreSession	(char* idClient);
char* rejoindrePartie	(char* idPartie, int partie);
char* regarderSession	(char* idClient);
char* regarderPartie	(char* idPartie,int partie);

//Manipulation du fichier "compte"
//Ajout d'une chaine de caractère à la fin du fichier.
void ajoutCompte		(FILE* fichier,char* chaine);
void decoReco			(FILE* fichier,long curseur,char nvChar);
int utiliserCompte		(char* compte ,int mode);

//Client
//Avoir indice coordP d'une case dans Damier à partir de ses coordonnées [x,y]
int caseAvecCoord(int x,int y);
//Avoir coordonnée [x,y] d'une case à partir de son indice coordP dans Damier
int* coordAvecCase(int coordP);
int* entreeJoueur(Case* Damier,int** MouvLegaux);
//------------------------------------------------------------------------------
int * transformCharToCouple(char * ChaineChar);
Case * transformCharToDamier(char * ChaineChar);
char * transformDamierToChar(Case * Damier);
char * transformCoupleToChar(Case * Damier,int Couple[2]);

Partie* genListePartie();
int indexCreerPartie(Partie* ListePartie);
#endif
