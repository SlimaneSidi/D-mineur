#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "includes/Niveau2.h"

Case mapMoyen[Longueur2][Hauteur2];

void initMap()
{
    for (int x = 0; x < Longueur2; x++)
    {
        for (int y = 0; y < Hauteur2; y++)
        {
            mapMoyen[x][y].mine = 0;
            mapMoyen[x][y].closestMine = 0;
            mapMoyen[x][y].caseRevealed = 0;
        }
    }
}

void afficheMap(int IsMine)
{
    for (int x = 0; x < Longueur2; x++)
    {
        for (int y = 0; y < Hauteur2; y++)
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
