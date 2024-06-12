#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "includes/genBombes.h"

void placeMines(int mines, int longueur, int hauteur, Case map[Longueur][Hauteur]) {
    srand(time(NULL));

    int placedMines = 0;

    while (placedMines < mines) {
        int x = rand() % longueur;
        int y = rand() % hauteur;
        if (!map[x][y].mine) {
            map[x][y].mine = 1;
            placedMines++;
        }
    }
}