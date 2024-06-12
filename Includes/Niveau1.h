#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()


#define Longueur 10
#define Hauteur 10
#define NbMines 10

typedef struct
{
    int mine;
    int closestMine;
    int caseRevealed;
}Case;

Case map;

void initMap();

void afficheMap(int IsMine);