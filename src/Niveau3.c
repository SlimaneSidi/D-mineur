#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../includes/Niveau3.h"

Case mapDifficile[Longueur3][Hauteur3];

void initMap(Case map[x][y], int longu, int haut)
{
    for (int i = 0; i < longu; i++)
    {
        for (int j = 0; j < haut; j++)
        {
            map[i][j].mine = 0;
            map[i][j].closestMine = 0;
            map[i][j].caseRevealed = 0;
        }
    }
}

void afficheMap(int IsMine)
{
    for (int i = 0; i < Longueur3; i++)
    {
        for (int j = 0; j < Hauteur3; j++)
        {
            if (mapDifficile[i][j].caseRevealed) {
                if (mapDifficile[i][j].mine) {
                    printf("* ");
                } else {
                    printf("%d ", mapDifficile[i][j].closestMine);
                }
            } else {
                if (IsMine && mapDifficile[i][j].mine) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
        }
    }
}
