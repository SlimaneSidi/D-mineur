#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "Niveau1.h"
#include "Niveau2.h"
#include "Niveau3.h"

int x, y;

void placeMines(int mines, int longueur, int hauteur, Case map);

void calculateAdjacentMines(int longueur, int hauteur, Case map);