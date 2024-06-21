#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../gfxlib/include/GfxLib.h"
#include "../gfxlib/include/BmpLib.h"


#define Longueur1 10
#define Hauteur1 15
#define NbMines1 18

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
#define LARGEUR_TABLEAU 10
#define HAUTEUR_TABLEAU 15
#define LARGEUR_GRILLE 300 //((LARGEUR_FENETRE*9/10)-(LARGEUR_FENETRE/4))
#define HAUTEUR_GRILLE 450 //((HAUTEUR_FENETRE*9/10)-(HAUTEUR_FENETRE/6))
#define NB_IMAGES 12  // 8 chiffres, 1 drapeau, 1 mine, 1 case vide


typedef struct cell
{
    int isMine;
    int closestMine;
    int cellRevealed;
} cell;


typedef struct Grille {
    int largeur;
    int hauteur;
    cell *cases;
} Grille; ///////////////////////nigga//////////////////////////////////////////////////////////////////////////////////////////////////Pourquoi on a besoin de pointeurs ? Parce que c'est un D MINEURS AHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAH oui 



void gestionEvenement(EvenementGfx evenement);
void initTab(int longu, int haut); // Terminal
void afficheTab(void);  // Terminal
void initialiseGrille(Grille *grille);
void dessineJeu(Grille *grille);
void dessineGrille(Grille *grille);
void chargeImages(void);
void libereImages(void);
void reveleCase(Grille *grille, int x, int y);
void marqueDrapeau(Grille *grille, int x, int y);
int compterMinesAdjacentes(const Grille *grille, int x, int y);


extern cell map[Longueur1][Hauteur1];

void gestionEvent(void);

void placeMines(int mines, int longueur, int hauteur);

void closestMines(int longueur, int hauteur);

void revealAdjacentCells(int x, int y, int longueur, int hauteur);

void zonesVides(int ligne, int colonne, cell map[][Hauteur1]);

void afficheMapComplete(void);

//void displayAdjacentEmptyCells(int x, int y, int longueur, int hauteur);

#endif