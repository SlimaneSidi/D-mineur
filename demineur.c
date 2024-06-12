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

    int x, y;
    printf("Entrez des coordonnées (x y): ");
    scanf("%d %d", &x, &y);

    int GAME = 0;

    if (x != NULL || y != NULL)
    {
        placeMines(NbMines, Longueur, Hauteur, mapFacile[x][y])
    }
    while (!GAME)
    {
        afficheMap(0);
    }


}
