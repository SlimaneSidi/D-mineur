#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../include/Niveau1.h"

Case mapFacile[Longueur1][Hauteur1];

void initMap()
{
    for (int i = 0; i < Longueur1; i++)
    {
        for (int j = 0; j < Hauteur1; j++)
        {
            mapFacile[i][j].mine = 0;
            mapFacile[i][j].closestMine = 0;
            mapFacile[i][j].caseRevealed = 0;
        }
    }
}

void afficheMap(int IsMine)
{
    for (int i = 0; i < Longueur1; i++)
    {
        for (int j = 0; j < Hauteur1; j++)
        {
            if (mapFacile[i][j].caseRevealed) {
                if (mapFacile[i][j].mine) {
                    printf("* ");
                } else {
                    printf("%d ", mapFacile[i][j].closestMine);
                }
            } else {
                if (IsMine && mapFacile[i][j].mine) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
        }
    }
}
