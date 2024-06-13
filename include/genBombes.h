#ifndef GEN_BOMBES_H
#define GEN_BOMBES_H

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include <time.h>
#include "Niveau1.h"


extern int x;
extern int y;

void placeMines(int mines, int longueur, int hauteur, Case map[x][y]);

void CalcClosestMine(int longueur, int hauteur, Case map[x][y]);

#endif