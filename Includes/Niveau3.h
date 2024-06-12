#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "Niveau1.h"

// DIFFICULTE 3

#define Longueur3 25
#define Hauteur3 20
#define NbMines3 100

Case map3[Longueur3][Hauteur3];

void initMap();

void afficheMap(int IsMine);