#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>

// DIFFICULTE 2

#define Longueur2 20
#define Hauteur2 15
#define NbMines2 45

typedef struct
{
    int mine;
    int closestMine;
    int caseRevealed;
}Case;

Case map2;

void initMap();

void afficheMap(int IsMine);