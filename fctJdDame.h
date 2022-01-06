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
//Créer le damier
Case * genJeu			(int tailleDamier);
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
#endif
