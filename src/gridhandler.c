#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../include/main.h"

void initTab(int longu, int haut)
{
    for (int i = 0; i < longu; i++)
    {
        for (int j = 0; j < haut; j++)
        {
            map[i][j].isMine = 0;
            map[i][j].closestMine = 0;
            map[i][j].cellRevealed = 0;
        }
    }

    return;
}

void afficheTab(void)
{

    // Afficher le tableau
    for (int x = 0; x < Hauteur1; x++)
    {
        for (int y = 0; y < Longueur1; y++)
        {
            if (map[x][y].cellRevealed == 1)
            {
                if (map[x][y].isMine)
                {
                    printf("* ");
                }
                else
                {
                    printf("%d ", map[x][y].closestMine);
                }
            }
            else
            {
                if (map[x][y].isMine)
                {
                    printf("* ");
                }
                else
                {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}
