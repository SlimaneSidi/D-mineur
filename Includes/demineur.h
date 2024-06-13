#ifndef DEMINEUR_H
#define DEMINEUR_H

#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "../includes/Niveau1.h"
#include "../includes/Niveau2.h"
#include "../includes/Niveau3.h"
#include "../includes/genBombes.h"
#include "../includes/menu.h"
#include "../includes/time.h"
#include "../includes/VictoireDefaite.h"

#define WindowLength largeurFenetre
#define WindowHeight hauteurFenetre
#define Timer 0

int x, y;
int difficultyChoix;

int nbChoix(int choix);
void initMap(Case map[x][y], int longu, int haut);
void JouerNiveau();

#endif