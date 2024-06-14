#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "../include/main.h"


cell map[Hauteur1][Longueur1];


int main(void)
{
    initTab(Longueur1, Hauteur1);

    gestionEvent();

    return 0;
}

void gestionEvent(void)
{
    int x, y;

    printf("Entrez les coordonnées de départ (x y): ");
    scanf("%d %d", &x, &y);

    map[x][y].cellRevealed = 1;

    placeMines(NbMines1, Longueur1, Hauteur1);

    afficheTab();
}

void placeMines(int mines, int longueur, int hauteur) 
{
    srand(time(NULL));

    int placedMines = 0;

    while (placedMines < mines) 
    {
        int i = rand() % longueur;
        int j = rand() % hauteur;
        if (!map[i][j].isMine) {
            map[i][j].isMine = 1;
            placedMines++;
        }
    }
}

