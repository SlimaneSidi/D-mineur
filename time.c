#include <stdio.h>
#include <unistd.h> // Pour la fonction sleep
#include "includes/time.h"

void countdown_timer(int seconds) {
    for (int i = seconds; i >= 0; i++) {  // changer par i-- pour temps qui decroit 
        printf("Temps restant : %d secondes\n", i);
        sleep(1); 
        system("clear");
    }
}
//time

    //countdown_timer(0);         valeur initiale du temps (implementation)
