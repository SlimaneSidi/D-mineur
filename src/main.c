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

    afficheTab();

    printf("Entrez les coordonnées de départ (x y): ");
    scanf("%d %d", &x, &y);

    map[x][y].cellRevealed = 1;

    placeMines(NbMines1, Longueur1, Hauteur1);
    closestMine(Longueur1, Hauteur1);

    afficheTab();

    int GAME = 0;

    while (GAME == 0)
    {
        printf("Entrez les coordonnées suivantes (x y): ");
        scanf("%d %d", &x, &y);

        if (map[x][y].isMine == 1)
        {
            printf("Vous avez touché une mine...\n la partie est terminée.\n");
            return;
        }
        else if (x == 98 || y == 98)
        {
            GAME = 1;
        }
        else 
        {
            closestMine(Longueur1, Hauteur1);
            map[x][y].cellRevealed = 1;
            afficheTab();
        }
    }
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

void closestMine(int longueur, int hauteur) 
{
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < hauteur; j++) {
            if (map[i][j].isMine) continue;
            int minesCount = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int newX = i + k;
                    int newY = j + l;
                    if (newX >= 0 && newX < longueur && newY >= 0 && newY < hauteur) {
                        if (map[newX][newY].isMine) {
                            minesCount++;
                            map[newX+1][newY+1].closestMine = minesCount;
                        }
                    }
                }
            }
            map[i][j].closestMine = minesCount;
        }
    }
}


