#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../Includes/demineur.h"


int nbChoix(int choix)
{   
    difficultyChoix = choix;
    return difficultyChoix;
}

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

    return;
}

void JouerNiveau(int choix)
{
    printf("Entrez des coordonnées (x y): ");
    scanf("%d %d", &x, &y);

    int GAME = 0;

    if (choix == 1)
    {
        Case map1[Longueur1][Hauteur1];
        initMap(map1, Longueur1, Hauteur1);

        if (x >= 0 || y >= 0)
        {
            placeMines(NbMines1, Longueur1, Hauteur1, map1);
        }
    }

    if (choix == 2)
    {
        Case map2[Longueur2][Hauteur2];
        initMap(map2, Longueur2, Hauteur2);

        if (x >= 0 || y >= 0)
        {
            placeMines(NbMines2, Longueur2, Hauteur2, map2);
        }
    }

    if (choix == 3)
    {
        Case map3[Longueur3][Hauteur3];
        initMap(map3, Longueur3, Hauteur3);

        if (x >= 0 || y >= 0)
        {
            placeMines(NbMines3, Longueur3, Hauteur3, map3);
        }
    }
    
    while (!GAME)
    {
        afficheMap(0);
    }
}

int main()
{
    menu();

    countdown_timer(Timer);

    JouerNiveau(difficultyChoix);
    
    //CalcClosestMine();
}