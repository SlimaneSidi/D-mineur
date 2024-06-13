#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../includes/Niveau1.h"
#include "../includes/genBombes.h"
#include "../includes/menu.h"
#include "../includes/time.h"
#include "../includes/VIctoireDefaite.h"

#define WindowLength largeurFenetre
#define WindowHeight hauteurFenetre
#define Timer 0

int x, y;

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

    return map;
}

void JouerNiveau1()
{
    printf("Entrez des coordonnées (x y): ");
    scanf("%d %d", &x, &y);

    int GAME = 0;

    if (x >= 0 || y >= 0)
    {
        placeMines(NbMines1, Longueur1, Hauteur1, map1);
    }
    while (!GAME)
    {
        afficheMap(0);
    }
}

/*void JouerNiveau2()
{
    printf("Entrez des coordonnées (x y): ");
    scanf("%d %d", &x, &y);

    int GAME = 0;

    if (x >= 0 || y >= 0)
    {
        placeMines(NbMines2, Longueur2, Hauteur2, map2);
    }
    while (!GAME)
    {
        afficheMap(0);
    }
}

void JouerNiveau3()
{
    printf("Entrez des coordonnées (x y): ");
    scanf("%d %d", &x, &y);

    int GAME = 0;

    if (x >= 0 || y >= 0)
    {
        placeMines(NbMines3, Longueur3, Hauteur3, map3);
    }
    while (!GAME)
    {
        afficheMap(0);
    }
}*/


int main()
{
    menu();

    countdown_timer(Timer);

    if (choix == 1)
    {
        Case map1[Longueur1][Hauteur1];
        initMap(map1[Longueur1][Hauteur1], Longueur1, Hauteur1);
    }
    
    //CalcClosestMine();
}