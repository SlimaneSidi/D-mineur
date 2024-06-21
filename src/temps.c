#include <stdio.h>
#include <time.h>
#include "../include/demineur.h"
#include "../include/temps.h"


int countdown_timer(int seconds) {
    time_t oldTime, currentTime;
    int chrono = 500;

    // prends le temps actuel et l'assimile a old time (fonction de time.h)
    time(&oldTime);

    while (chrono < seconds) {

        time(&currentTime);

        if (difftime(currentTime, oldTime) >= 1) {    //peut aussi utiliser (currentTime - oldTime >= 1)
            chrono--;
            oldTime = currentTime;

            printf("Temps restant: %d secondes\n", chrono);
        }
    }

    return chrono;
}



