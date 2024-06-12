#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "includes/Niveau1.h"
#include "includes/Niveau2.h"
#include "includes/Niveau3.h"

#define WindowLength largeurFenetre
#define WindowHeight hauteurFenetre
#define Timer 0


int main()
{
    menu();

    countdown_timer(Timer);
    initMap();
    CalcClosestMine();
}

void JouerNiveau1()
{
    int x, y;
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

void JouerNiveau2()
{
    int x, y;
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
    int x, y;
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
}
