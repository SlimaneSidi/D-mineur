#include "../include/demineur.h"
#include "../include/temps.h"

int main(int argc, char **argv) {


    

 //fonction demineur.c
    initialiseGfx(argc, argv);
    prepareFenetreGraphique("Démineur Facile", LARGEUR_FENETRE, HAUTEUR_FENETRE);
    lanceBoucleEvenements();

 //fonction temps.c
    int duration = 501; // duree max
    countdown_timer(duration);


    return 0;
}

