#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pour usleep()

#define DELAI 1000000


void effaceConsole(void);
void attendre(double duree);
int menuPrincipal(void);
int menuJouer(void);
void menuManuel(void);
int menu(void);
int menuApresJeu(void);