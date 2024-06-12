#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>

// DIFFICULTE 3

#define Longueur3 25
#define Hauteur3 20
#define NbMines3 10

typedef struct
{
    int mine;
    int closestMine;
    int caseRevealed;
}Case;

Case map3;

void initMap();

void afficheMap(int IsMine);