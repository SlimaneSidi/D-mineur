#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()
#include <math.h>
#include "GfxLib.h" // Seul cet include est necessaire pour faire du graphique
#include "BmpLib.h" // Cet include permet de manipuler des fichiers BMP
#include "ESLib.h" // Pour utiliser valeurAleatoire()

#define WindowLength largeurFenetre
#define WindowHeight hauteurFenetre
#define Timer 0


int main()
{
    menu();
    countdown_timer(Timer);
    initMap();

    int x, y;
    printf("Entrez des coordonnées (x y): ");
    scanf("%d %d", &x, &y);

    int GAME = 0;

    if (x != NULL || y != NULL)
    {
        afficheMap(0);
    }
    while (!GAME)
    {

    }


}
