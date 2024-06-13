#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../includes/genBombes.h"

void placeMines(int mines, int longueur, int hauteur, Case map[x][y]) 
{
    srand(time(NULL));

    int placedMines = 0;

    while (placedMines < mines) 
    {
        int i = rand() % longueur;
        int j = rand() % hauteur;
        if (!map[i][j].mine) {
            map[i][j].mine = 1;
            placedMines++;
        }
    }
}

void CalcClosestMine(int longueur, int hauteur, Case map[x][y]) 
{
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < hauteur; j++) {
            if (map[i][j].mine) continue;
            int minesCount = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    int newX = i + k;
                    int newY = j + l;
                    if (newX >= 0 && newX < longueur && newY >= 0 && newY < hauteur) {
                        if (map[newX][newY].mine) {
                            minesCount++;
                        }
                    }
                }
            }
            map[i][j].closestMine = minesCount;
        }
    }
}