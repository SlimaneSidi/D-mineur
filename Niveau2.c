#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "includes/Niveau2.h"

Case mapMoyen[Longueur][Hauteur];

void initMap()
{
    for (int x = 0; x < Longueur; x++)
    {
        for (int y = 0; y < Hauteur; y++)
        {
            mapMoyen[x][y].mine = 0;
            mapMoyen[x][y].closestMine = 0;
            mapMoyen[x][y].caseRevealed = 0;
        }
    }
}

void afficheMap(int IsMine)
{
    for (int x = 0; x < Longueur; x++)
    {
        for (int y = 0; y < Hauteur; y++)
        {
            if (mapMoyen[x][y].caseRevealed) {
                if (mapMoyen[x][y].mine) {
                    printf("* ");
                } else {
                    printf("%d ", mapMoyen[x][y].closestMine);
                }
            } else {
                if (IsMine && mapMoyen[x][y].mine) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
        }
    }
}