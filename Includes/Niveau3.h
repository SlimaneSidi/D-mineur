#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()

// DIFFICULTE 3

#define Longueur 25
#define Hauteur 20
#define NbMines 10

typedef struct
{
    int mine;
    int closestMine;
    int caseRevealed;
}Case;

Case map3;

void initMap();

void afficheMap(int IsMine);