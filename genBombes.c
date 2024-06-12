#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "includes/genBombes.h"

void placeMines(int mines, int longueur, int hauteur, Case map[x][y]) 
{
    srand(time(NULL));

    int placedMines = 0;

    while (placedMines < mines) 
    {
        int x = rand() % longueur;
        int y = rand() % hauteur;
        if (!map[x][y].mine) {
            map[x][y].mine = 1;
            placedMines++;
        }
    }
}

void CalcClosestMine(int longueur, int hauteur, Case map[x][y]) 
{
    for (int x = 0; x < longueur; x++) {
        for (int y = 0; y < hauteur; y++) {
            if (map[x][y].mine) continue;
            int minesCount = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int newX = x + i;
                    int newY = y + j;
                    if (newX >= 0 && newX < longueur && newY >= 0 && newY < hauteur) {
                        if (map[newX][newY].mine) {
                            minesCount++;
                        }
                    }
                }
            }
            map[x][y].closestMine = minesCount;
        }
    }
}