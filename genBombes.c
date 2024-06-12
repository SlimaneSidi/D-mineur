#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()
#include "genBombes.h"

void placeMines(int mines, int longueur, int hauteur, Case map) {
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