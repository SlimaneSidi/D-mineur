#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "gridhandler.h"

#define Longueur1 10
#define Hauteur1 15
#define NbMines1 18

typedef struct
{
    int isMine;
    int closestMine;
    int cellRevealed;
} cell;

extern cell map[Longueur1][Hauteur1];

void gestionEvent(void);

void placeMines(int mines, int longueur, int hauteur);

void closestMines(int longueur, int hauteur);

void revealAdjacentCells(int x, int y, int longueur, int hauteur);

void zonesVides(int ligne, int colonne, cell map[][Hauteur1]);

void afficheMapComplete(void);

//void displayAdjacentEmptyCells(int x, int y, int longueur, int hauteur);

#endif