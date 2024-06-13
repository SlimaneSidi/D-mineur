int baisetesmorts; 
#include <stdio.h>
#include <time.h>

int countdown_timer(int seconds) {
    time_t oldTime, currentTime;
    int chrono = 0;

    // prends le temps actuel et l'assimile a old time (fonction de time.h)
    time(&oldTime);

    while (chrono < seconds) {

        time(&currentTime);

        if (difftime(currentTime, oldTime) >= 1) {    //peut aussi utiliser (currentTime - oldTime >= 1)
            chrono++;
            oldTime = currentTime;

            printf("Temps ecoule: %d secondes\n", chrono);
        }
    }

    return chrono;
}


////////////////////////////////////////
int main() {
    int duration = 10; // duree max
    countdown_timer(duration);
    return 0;
}

