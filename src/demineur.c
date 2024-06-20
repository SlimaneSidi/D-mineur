#include "../include/demineur.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define NB_IMAGES 12





DonneesImageRGB* images[NB_IMAGES];  // Tableau pour stocker les images chargées

DonneesImageRGB* compresseImage(DonneesImageRGB *image) {
    int largeur_case = LARGEUR_GRILLE / LARGEUR_TABLEAU;
    int hauteur_case = HAUTEUR_GRILLE / HAUTEUR_TABLEAU;
    DonneesImageRGB* nimage = malloc(sizeof(DonneesImageRGB));

    nimage->largeurImage = largeur_case;
    nimage->hauteurImage = hauteur_case;
    nimage->donneesRGB = malloc(3 * largeur_case * hauteur_case * sizeof(char));

    for (int y = 0; y < hauteur_case; y++) {
        for (int x = 0; x < largeur_case; x++) {
            int srcX = x * image->largeurImage / largeur_case;
            int srcY = y * image->hauteurImage / hauteur_case;
            int srcIndex = (srcY * image->largeurImage + srcX) * 3;
            int destIndex = (y * largeur_case + x) * 3;
            nimage->donneesRGB[destIndex] = image->donneesRGB[srcIndex];
            nimage->donneesRGB[destIndex + 1] = image->donneesRGB[srcIndex + 1];
            nimage->donneesRGB[destIndex + 2] = image->donneesRGB[srcIndex + 2];
        }
    }

    return nimage;
}

void chargeImages() {
    char filename[20];
    for (int i = 0; i < 4; i++) {
        sprintf(filename, "./BMP/%d.bmp", i + 1);
        images[i] = compresseImage(lisBMPRGB(filename));
        if (!images[i]) {
            fprintf(stderr, "Failed to load image %s\n", filename);
        }
    }
    // Assure-toi que les images spéciales sont également chargées correctement.
    images[9] = lisBMPRGB("./BMP/drapeau.bmp");
    images[10] = lisBMPRGB("./BMP/mine.bmp");
    images[11] = lisBMPRGB("./BMP/case.bmp");
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
    grille->cases = malloc(grille->largeur * grille->longueur * sizeof(cell));
    for (int y = 0; y < grille->longueur; y++) {
        for (int x = 0; x < grille->largeur; x++) {
            grille->cases[y * grille->largeur + x] = (cell){false, rand() % 6 == 0, false, 0}; // Initialiser nbMines à 0 ou autre logique appropriée
        }
    }
}




void dessineJeu(Grille *grille) {
    effaceFenetre(128, 128, 128);
    couleurCourante(96, 96, 96);
    epaisseurDeTrait(2);
    rectangle(LARGEUR_FENETRE / 4, HAUTEUR_FENETRE / 6, LARGEUR_FENETRE * 9 / 10, HAUTEUR_FENETRE * 9 / 10);
    dessineGrille(grille);
}

 void dessineGrille(Grille *grille) {
     int largeur_grille = (LARGEUR_FENETRE * 9 / 10) - (LARGEUR_FENETRE / 4);
    int hauteur_grille = (HAUTEUR_FENETRE * 9 / 10) - (HAUTEUR_FENETRE / 6);

     for (int y = 0; y < grille->longueur; y++) {
         for (int x = 0; x < grille->largeur; x++) {
            int posX = x * (largeur_grille / LARGEUR_TABLEAU) + LARGEUR_FENETRE / 4;
             int posY = y * (hauteur_grille / HAUTEUR_TABLEAU) + HAUTEUR_FENETRE / 6;
            int index = 11;  // Index par défaut pour une case non révélée
            if (grille->cases[y * grille->largeur + x].estRevelee) {
                 index = grille->cases[y * grille->largeur + x].estMine ? 10 : grille->cases[y * grille->largeur + x].nbMines;
                if (index > 4) index = 11; // S'assurer que l'index reste valide
            } else if (grille->cases[y * grille->largeur + x].estMarquee) {
                index = 9;  // Index pour le drapeau
           }
            ecrisImage(posX, posY, images[index]->largeurImage, images[index]->hauteurImage, images[index]->donneesRGB);
        }
     }
 }


// void dessineGrille(Grille *grille){




void gestionEvenement(EvenementGfx evenement) {
    static Grille grille = {LARGEUR_TABLEAU, HAUTEUR_TABLEAU, NULL};
    switch (evenement) {
        case Initialisation:
            chargeImages();
            initialiseGrille(&grille);
            demandeTemporisation(20);
            break;
        case Temporisation:
            rafraichisFenetre();
            break;
        case Affichage:
            dessineJeu(&grille);
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
                int x = (abscisseSouris() - LARGEUR_FENETRE / 4) * LARGEUR_TABLEAU / LARGEUR_FENETRE;
                int y = (ordonneeSouris() - HAUTEUR_FENETRE / 6) * HAUTEUR_TABLEAU / HAUTEUR_FENETRE;
                reveleCase(&grille, x, y);
            } else if (etatBoutonSouris() == DroiteAppuye) {
                int x = (abscisseSouris() - LARGEUR_FENETRE / 4) * LARGEUR_TABLEAU / LARGEUR_FENETRE;
                int y = (ordonneeSouris() - HAUTEUR_FENETRE / 6) * HAUTEUR_TABLEAU / HAUTEUR_FENETRE;
                marqueDrapeau(&grille, x, y);
            }
            break;
        default:
            break;
    }
}

void reveleCase(Grille *grille, int x, int y) {
    cell *c = &grille->cases[y * grille->largeur + x];
    if (!c->estRevelee && !c->estMarquee) {
        c->estRevelee = true;
        if (c->estMine) {
            // Logique de fin de jeu, montrer toutes les mines par exemple
        } else {
            int adjacentMines = compterMinesAdjacentes(grille, x, y);
            if (adjacentMines == 0) {
                // Révéler récursivement les cases adjacentes sans mines
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dx != 0 || dy != 0) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && nx < grille->largeur && ny >= 0 && ny < grille->longueur && !grille->cases[ny * grille->largeur + nx].estRevelee) {
                                reveleCase(grille, nx, ny);
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
        cell *c = &grille->cases[y * grille->largeur + x];
        if (!c->estRevelee) {
            c->estMarquee = !c->estMarquee;
        }
    }
}

int compterMinesAdjacentes(const Grille *grille, int x, int y) {
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

