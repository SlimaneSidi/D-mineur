#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../include/difficultes.h"

Case mapFacile[Longueur1][Hauteur1];
Case mapMoyen[Longueur2][Hauteur2];
Case mapDifficile[Longueur3][Hauteur3];

void initMap(int difficulte)
{
    if (difficulte > 3 || difficulte < 1)
    {   
        int choix;
        printf("Il n'y a que 3 difficultés, veuillez rerenseigner votre choix :\n");
        scanf("%d", &choix);
        initMap(choix);
    }
    else if (difficulte == 1)
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

    else if (difficulte == 2)
    {
        for (int i = 0; i < Longueur2; i++)
        {
            for (int j = 0; j < Hauteur2; j++)
            {
                mapFacile[i][j].mine = 0;
                mapFacile[i][j].closestMine = 0;
                mapFacile[i][j].caseRevealed = 0;
            }
        }  
    }

    else if (difficulte == 3)
    {
        for (int i = 0; i < Longueur3; i++)
        {
            for (int j = 0; j < Hauteur3; j++)
            {
                mapFacile[i][j].mine = 0;
                mapFacile[i][j].closestMine = 0;
                mapFacile[i][j].caseRevealed = 0;
            }
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
