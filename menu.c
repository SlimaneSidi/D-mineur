#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // pour usleep()

#define DELAI 1000000

void effaceConsole(void) {
    if (system("clear") != 0) {
        printf("La console n'a pas pu être effacée...\n");
    }
}

void attendre(double duree) {
    usleep(duree * DELAI);
}

int menu(void) {
    while (menuPrincipal() != 3) {
        // boucle principale du menu, quitte si l'option 3 est choisie
    }
    return 0;
}

int menuPrincipal(void) {
    int choix = 0;
    effaceConsole();
	printf("||---------------------------------------------||\n");
	printf("||------------┬ ┬┌─┐┬  ┌─┐┌─┐┌┬┐┌─┐------------||\n");
	printf("||------------│││├┤ │  │  │ ││││├┤ ------------||\n");
	printf("||------------└┴┘└─┘┴─┘└─┘└─┘┴ ┴└─┘------------||\n");
	printf("||---------------------------------------------||\n");
	printf("\n");
    printf("||---------------------------------------------||\n");
    printf("||---------------------------------------------||\n");
	printf("||-----------┌┬┐┌─┐┌┬┐┬┌┐ ┬┌─┐┬ ┬┌─┐-----------||\n");
	printf("||----------- ││├┤ │││││└┐│├┤ │ │├┬┘-----------||\n");
	printf("||-----------─┴┘└─┘┴ ┴┴┴ └┘└─┘└─┘┴└┘-----------||\n");
	printf("||---------------------------------------------||\n");
    printf("||---------------------------------------------||\n");
    printf("||------------------1 - Jouer------------------||\n");
    printf("||----------2 - Manuel d'utilisation-----------||\n");
    printf("||------------------3 - Quitter----------------||\n");
    printf("||---------------------------------------------||\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
            while (menuJouer() != 2) {
                // Boucle du menu jouer, retourne au menu principal si l'option 2 est choisie
            }
            break;
        case 2:
            menuManuel();
            break;
        case 3:
            return 3; // Quitter
    }
    return 0;
}

int menuJouer(void) {
    int choix = 0;
    effaceConsole();
    printf("||---------------------------------------------||\n");
    printf("||-----------------CHOISISSEZ------------------||\n");
    printf("||----------------LA DIFFICULTÉ----------------||\n");
    printf("||-----------------1 - Facile------------------||\n");
    printf("||-----------------2 - Moyen-------------------||\n");
    printf("||-----------------3 - Difficile---------------||\n");
    printf("||---------------------------------------------||\n");
    printf("Votre choix: ");
    scanf("%d", &choix);

    switch (choix) {
        case 1:
        case 2:
        case 3:
        case 4:
            return menuApresJeu();
        printf("Lancement du jeu en difficulté %d...\n", choix);
            attendre(2); // Attente avant de continuer
    }
    return choix;
}

int menuApresJeu(void) {
    int choix = 0;
    printf("||---------------------------------------------||\n");
    printf("||-----------------1 - Recommencer------------||\n");
    printf("||----------2 - Retour au menu principal------||\n");
    printf("||-----------------3 - Quitter----------------||\n");
    printf("||---------------------------------------------||\n");
    printf("Votre choix: ");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            return 0; // Recommence le jeu
        case 2:
            return 2; // Retour au menu principal
        case 3:
            exit(EXIT_SUCCESS); // Quitte le programme
    }
    return 0;
}

void menuManuel(void) {
    effaceConsole();
    printf("||---------------------------------------------||\n");
    printf("||-------------MANUEL D'UTILISATION-----------||\n");
    printf("||---------------------------------------------||\n");
    printf("Les règles du démineur sont patati patata...\n");
    printf("||---------------------------------------------||\n");
    attendre(60); // Affiche le manuel pendant 60 secondes
}

