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

    rocknigg(x, y, x, y, map);

    map[x][y].cellRevealed = 1;

    placeMines(NbMines1, Longueur1, Hauteur1);
    closestMines(Longueur1, Hauteur1);
    revealAdjacentCells(x, y, Longueur1, Hauteur1);
   



    afficheTab();

    printf("\n");
    printf("----------- Map debug : -----------\n");
    printf("\n");

    afficheMapComplete();

    int GAME = 0;

    while (GAME == 0)
    {
        printf("Entrez les coordonnées suivantes (x y): ");
        scanf("%d %d", &x, &y);
        printf("\n");

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
            rocknigg(x, y, x, y, map); //connard
            closestMines(Longueur1, Hauteur1);
            map[x][y].cellRevealed = 1;
            revealAdjacentCells(x, y, Longueur1, Hauteur1);

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

void closestMines(int longueur, int hauteur) {
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < hauteur; j++) {

            int minesCount = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int newX = i + k;
                    int newY = j + l;

                    if (newX >= 0 && newX < longueur && newY >= 0 && newY < hauteur) {
                        if (map[newX][newY].isMine) {
                            minesCount++;
                        }
                    }
                }
            }

            map[i][j].closestMine = minesCount;
        }
    }
}


void revealAdjacentCells(int x, int y, int longueur, int hauteur) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newX = x + i;
            int newY = y + j;

            if (newX >= 0 && newX < longueur && newY >= 0 && newY < hauteur) {
                if (!map[newX][newY].cellRevealed && !map[newX][newY].isMine) {
                    map[newX][newY].cellRevealed = 1;
                }
            }
        }
    }
}

void rocknigg(int x, int y, int ligne, int colonne, cell map[][Longueur1]) {
    if (ligne == x || colonne == y || ligne < 0 || ligne >= Hauteur1 || colonne < 0 || colonne >= Longueur1 || map[ligne][colonne].cellRevealed || map[ligne][colonne].isMine)
        return;

    map[ligne][colonne].cellRevealed = 1;

    if (map[ligne][colonne].closestMine == 0) {
        for (int x = -1; x <= 1; x++) {
            for (int y = -1; y <= 1; y++) {
                int temp_i = ligne + x;
                int temp_j = colonne + y;

                if (temp_i >= 0 && temp_i < Hauteur1 && temp_j >= 0 && temp_j < Longueur1 && !map[temp_i][temp_j].cellRevealed && !map[temp_i][temp_j].isMine) {
                    rocknigg(x, y, temp_i, temp_j, map);
                }
            }
        }
    }
}
 

void afficheMapComplete(void) {
    for (int i = 0; i < Hauteur1; i++) {
        for (int j = 0; j < Longueur1; j++) {
            map[i][j].cellRevealed = 1;
        }
    }
    afficheTab();
}

