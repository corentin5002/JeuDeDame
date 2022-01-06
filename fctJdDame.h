#ifndef MAIN_H
#define MAIN_H

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
//==============================================================================
//structure d'une case du Damier------------------------------------------------
typedef struct Case Case;
struct Case
{
	int dame  ; //Si la case contient un pion = FALSE sinon = TRUE
	int equipe; //Si la case contient un pion du J1, du J2 ou une case vide (1,2,0)
	int etat  ; //Marqueur pour les différentes fonctions.
};

//FONCTIONS=====================================================================

//outils
Case * genJeu			(int tailleDamier);
void bougerPiece		(Case* Damier,int cDepart,int cArrivee);
void prettyPrint		(Case* Damier);
void prettyPrintDamier	(Case* Damier);
void prettyPrintPassage (Case* Damier);
void setCase			(Case* Damier,int coord,Case cNvl);
int  ennemie			(Case pion);
Case* cpyDamier			(Case* Damier);
int* direction		(int coordP);
//outils pour les tableaux
int** ajoutTab2D        (int** Tab2D,int* tab);
void supprTab2D         (int** Tab2D);
int** genTab2D          ();
void printTab2D			(int** Tab2D,int taillePetitTab);
//fonctions serveur
int** prioMouvement     (Case* Damier, int equipe);

//Damiers type
void damierType1        (Case * Damier,int tailleDamier);
void damierType2        (Case * Damier,int tailleDamier);
void damierType3        (Case * Damier,int tailleDamier);
void damierType4        (Case * Damier,int tailleDamier);

//==============================================================================
int* exploreCheminEnnemie(Case* DamierR,int compt,int coordP,int equipe);
//==============================================================================


//==============================================================================
#endif
