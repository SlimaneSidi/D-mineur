#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "Niveau1.h"

#define Longueur 10
#define Hauteur 10

Case mapFacile[Longueur][Hauteur];

void initMap()
{
    for (int x = 0; x < Longueur; x++)
    {
        for (int y = 0; y < Hauteur; y++)
        {
            mapFacile[x][y].mine = 0;
            mapFacile[x][y].closestMine = 0;
            mapFacile[x][y].caseRevealed = 0;
        }
    }
}

void afficheMap()

