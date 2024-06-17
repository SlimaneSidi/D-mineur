#include "../include/demineur.h" 

int main(int argc, char **argv) {
    initialiseGfx(argc, argv);
    prepareFenetreGraphique("Démineur Facile", 800, 600);
    lanceBoucleEvenements();
    return 0;
}

