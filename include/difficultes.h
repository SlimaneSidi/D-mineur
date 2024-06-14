#ifndef DIFFICULTES_H
#define DIFFICULTES_H

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>

// DIFFICULTE

#define Longueur1 15
#define Hauteur1 10

#define Longueur2 20
#define Hauteur2 15

#define Longueur3 25
#define Hauteur3 20

#define NbMines1 18
#define NbMines2 45
#define NbMines3 100


typedef struct {
    int mine;
    int closestMine;
    int caseRevealed;
} Case;

extern Case map1[Longueur1][Hauteur1];
extern Case map2[Longueur2][Hauteur2];
extern Case map3[Longueur3][Hauteur2];

void initMap();

void afficheMap(int IsMine);

#endif