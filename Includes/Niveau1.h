#ifndef NIVEAU1_H
#define NIVEAU1_H

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>

// DIFFICULTE 1

#define Longueur1 15
#define Hauteur1 10
#define NbMines1 18

typedef struct {
    int mine;
    int closestMine;
    int caseRevealed;
} Case;

Case map1[Longueur1][Hauteur1];

void initMap();

void afficheMap(int IsMine);

#endif