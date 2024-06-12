#include <stdlib.h> // Pour pouvoir utiliser exit()
#include <stdio.h> // Pour pouvoir utiliser printf()

void defaite() {
    printf("Vous avez cliqué sur une mine ! Vous avez explosé!\n");
    menu();
}

void victoire(){
    printf("Vous etes pas mort barvo !\n");
    menu();
}

