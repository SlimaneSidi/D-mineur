#include "../include/demineur.h" 

int main(int argc, char **argv) {
    initialiseGfx(argc, argv);
    prepareFenetreGraphique("Démineur Facile", LARGEUR_FENETRE, HAUTEUR_FENETRE);
    lanceBoucleEvenements();
    return 0;
}

