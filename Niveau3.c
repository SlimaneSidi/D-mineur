#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "includes/Niveau3.h"

Case mapDifficile[Longueur][Hauteur];

void initMap()
{
    for (int x = 0; x < Longueur; x++)
    {
        for (int y = 0; y < Hauteur; y++)
        {
            mapDifficile[x][y].mine = 0;
            mapDifficile[x][y].closestMine = 0;
            mapDifficile[x][y].caseRevealed = 0;
        }
    }
}

void afficheMap(int IsMine)
{
    for (int x = 0; x < Longueur; x++)
    {
        for (int y = 0; y < Hauteur; y++)
        {
            if (mapDifficile[x][y].caseRevealed) {
                if (mapDifficile[x][y].mine) {
                    printf("* ");
                } else {
                    printf("%d ", mapDifficile[x][y].closestMine);
                }
            } else {
                if (IsMine && mapDifficile[x][y].mine) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
        }
    }
}
