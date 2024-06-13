#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../include/Niveau2.h"

Case mapMoyen[Longueur2][Hauteur2];

void initMap()
{
    for (int i = 0; i < Longueur2; i++)
    {
        for (int j = 0; j < Hauteur2; j++)
        {
            mapMoyen[i][j].mine = 0;
            mapMoyen[i][j].closestMine = 0;
            mapMoyen[i][j].caseRevealed = 0;
        }
    }
}

void afficheMap(int IsMine)
{
    for (int i = 0; i < Longueur2; i++)
    {
        for (int j = 0; j < Hauteur2; j++)
        {
            if (mapMoyen[i][j].caseRevealed) {
                if (mapMoyen[i][j].mine) {
                    printf("* ");
                } else {
                    printf("%d ", mapMoyen[i][j].closestMine);
                }
            } else {
                if (IsMine && mapMoyen[i][j].mine) {
                    printf("* ");
                } else {
                    printf(". ");
                }
            }
        }
    }
}
