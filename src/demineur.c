#include "../include/demineur.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

DonneesImageRGB *images[NB_IMAGES];

void chargeImages() {
    char filename[20];
    for (int i = 0; i <= 8; i++) {
        sprintf(filename, "%d.bmp", i);
        images[i] = lisBMPRGB(filename);
    }
    images[9] = lisBMPRGB("drapeau.bmp");
    images[10] = lisBMPRGB("mine.bmp");
}

void libereImages() {
    for (int i = 0; i < NB_IMAGES; i++) {
        if (images[i]) {
            libereDonneesImageRGB(&images[i]);
        }
    }
}

void initialiseGrille(Grille *grille) {
    srand(time(NULL));
    grille->cases = malloc(grille->largeur * grille->longueur * sizeof(Case));
    for (int y = 0; y < grille->longueur; y++) {
        for (int x = 0; x < grille->largeur; x++) {
            grille->cases[y * grille->largeur + x] = (Case){0, 0, 0};
            if (rand() % 6 == 0) {  // 1 chance sur 6 d'être une mine
                grille->cases[y * grille->largeur + x].estMine = true;
            }
        }
    }
}

void dessineGrille(const Grille *grille) {
    effaceFenetre(255, 255, 255);
    for (int y = 0; y < grille->longueur; y++) {
        for (int x = 0; x < grille->largeur; x++) {
            int posX = x * TAILLE_CASE;
            int posY = y * TAILLE_CASE;
            if (grille->cases[y * grille->largeur + x].estRevelee) {
                if (grille->cases[y * grille->largeur + x].estMine) {
                    ecrisImage(posX, posY, images[10]->largeurImage, images[10]->hauteurImage, images[10]->donneesRGB);
                } else {
                    int minesAdj = compterMinesAdjacentes(grille, x, y);
                    if (minesAdj > 0) { // Dessiner chiffre correspondant
                        ecrisImage(posX, posY, images[minesAdj - 1]->largeurImage, images[minesAdj - 1]->hauteurImage, images[minesAdj - 1]->donneesRGB);
                    }
                }
            } else if (grille->cases[y * grille->largeur + x].estMarquee) {
                ecrisImage(posX, posY, images[9]->largeurImage, images[9]->hauteurImage, images[9]->donneesRGB);
            }
        }
    }
}

void gestionEvenement(EvenementGfx evenement) {
    static Grille grille = {LARGEUR, HAUTEUR, NULL};

    switch (evenement) {
        case Initialisation:
            chargeImages();
            initialiseGrille(&grille);
            demandeTemporisation(20);
            break;
        
        case Temporisation:
            // Rien à faire ici pour le moment
            rafraichisFenetre();
            break;

        case Affichage:
            dessineGrille(&grille);
            break;

        case Clavier:
            if (caractereClavier() == 'q') { // Quitter le jeu
                libereImages();
                if (grille.cases) {
                    free(grille.cases);
                }
                termineBoucleEvenements();
                exit(0);
            }
            break;

        case BoutonSouris:
            if (etatBoutonSouris() == GaucheAppuye) {
                int x = abscisseSouris() / TAILLE_CASE;
                int y = ordonneeSouris() / TAILLE_CASE;
                reveleCase(&grille, x, y);
            } else if (etatBoutonSouris() == DroiteAppuye) {
                int x = abscisseSouris() / TAILLE_CASE;
                int y = ordonneeSouris() / TAILLE_CASE;
                marqueDrapeau(&grille, x, y);
            }
            break;

        default:
            break;
    }
}

void reveleCase(Grille *grille, int x, int y) {
    if (x >= 0 && x < grille->largeur && y >= 0 && y < grille->longueur) {
        Case *c = &grille->cases[y * grille->largeur + x];
        if (!c->estRevelee && !c->estMarquee) {
            c->estRevelee = true;
            if (c->estMine) {
                // Logique pour gérer la fin du jeu
            } else {
                int adjacentMines = compterMinesAdjacentes(grille, x, y);
                if (adjacentMines == 0) {
                    // Révéler récursivement les cases adjacentes
                    for (int dy = -1; dy <= 1; dy++) {
                        for (int dx = -1; dx <= 1; dx++) {
                            if (dx != 0 || dy != 0) {
                                reveleCase(grille, x + dx, y + dy);
                            }
                        }
                    }
                }
            }
        }
    }
}

void marqueDrapeau(Grille *grille, int x, int y) {
    if (x >= 0 && x < grille->largeur && y >= 0 && y < grille->longueur) {
        Case *c = &grille->cases[y * grille->largeur + x];
        if (!c->estRevelee) {
            c->estMarquee = !c->estMarquee;
        }
    }
}

int compterMinesAdjacentes(Grille *grille, int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx < grille->largeur && ny >= 0 && ny < grille->longueur) {
                if (grille->cases[ny * grille->largeur + nx].estMine) {
                    count++;
                }
            }
        }
    }
    return count;
}


