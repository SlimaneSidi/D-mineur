#ifndef DEMINEUR_H
#define DEMINEUR_H

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "Niveau1.h"
#include "Niveau2.h"
#include "Niveau3.h"
#include "genBombes.h"
#include "time.h"
#include "VictoireDefaite.h"

#define WindowLength largeurFenetre
#define WindowHeight hauteurFenetre
#define Timer 0

int difficultyChoix;

int nbChoix(int choix);
void initMap(Case map[x][y], int longu, int haut);
void JouerNiveau();

#endif