#include "../include/demineur.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

DonneesImageRGB* compresseImage(DonneesImageRGB *image);

DonneesImageRGB *images[NB_IMAGES];

void chargeImages() {
    char filename[20];
    for (int i = 0; i <= 8; i++) {
        sprintf(filename, "./BMP/%d.bmp", i);
        images[i] = compresseImage(lisBMPRGB(filename));
    }
    images[9] = lisBMPRGB("./BMP/drapeau.bmp");
    images[10] = lisBMPRGB("./BMP/mine.bmp");
    images[11] = lisBMPRGB("./BMP/case.bmp");
}

DonneesImageRGB* compresseImage(DonneesImageRGB *image) {
    unsigned char* pix = malloc(3*sizeof(char));

    int largeur_case = LARGEUR_GRILLE/LARGEUR_TABLEAU;
    int hauteur_case = HAUTEUR_GRILLE/HAUTEUR_TABLEAU;

    DonneesImageRGB* nimage = malloc(sizeof(DonneesImageRGB));
    nimage->largeurImage = (image->largeurImage/largeur_case);
    nimage->hauteurImage = (image->hauteurImage/hauteur_case);

    for (int i=0; i<HAUTEUR_GRILLE; i+(nimage->hauteurImage)) {
        for (int j=0; j<LARGEUR_GRILLE; j+(nimage->largeurImage)) {
            //il faut juste avoir le pixel adéquat (r,g,b)
            pos = i*HAUTEUR_TABLEAU+j;
            pix = 
            nimage->donneesRGB = strcat(nimage->donneesRGB, pix);
        }
    }

    return nimage; 
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
        }
    }
}

void dessineJeu(Grille *grille) {
    // affiche fond gris
    effaceFenetre(128, 128, 128);

    // affiche grille jeu
    couleurCourante(96, 96, 96);
    epaisseurDeTrait(2);
    rectangle(LARGEUR_FENETRE/4, HAUTEUR_FENETRE/6, LARGEUR_FENETRE*9/10, HAUTEUR_FENETRE*9/10);
    dessineGrille(grille);
}

void dessineGrille(Grille *grille) {
    
    int largeur_grille = (LARGEUR_FENETRE*9/10)-(LARGEUR_FENETRE/4);
    int hauteur_grille = (HAUTEUR_FENETRE*9/10)-(HAUTEUR_FENETRE/6);

    ecrisImage(LARGEUR_FENETRE/4, HAUTEUR_FENETRE/6, images[1]->largeurImage, images[1]->hauteurImage, images[1]->donneesRGB);

    // for (int y = 0; y < grille->longueur; y++) {
    //     for (int x = 0; x < grille->largeur; x++) {
    //         int posX = x * (largeur_grille/LARGEUR_TABLEAU);
    //         int posY = y * (hauteur_grille/HAUTEUR_TABLEAU);
    //         if (grille->cases[y * grille->largeur + x].estRevelee) {
    //             if (grille->cases[y * grille->largeur + x].estMine) {
    //                 ecrisImage(posX, posY, images[10]->largeurImage, images[10]->hauteurImage, images[10]->donneesRGB);
    //             } else {
    //                 int minesAdj = compterMinesAdjacentes(grille, x, y);
    //                 if (minesAdj > 0) { // Dessiner chiffre correspondant
    //                     ecrisImage(posX, posY, images[minesAdj - 1]->largeurImage, images[minesAdj - 1]->hauteurImage, images[minesAdj - 1]->donneesRGB);
    //                 }
    //             }
    //         } else {
    //             ecrisImage(LARGEUR_FENETRE/4 + posX, HAUTEUR_FENETRE/6 + posY, largeur_grille/LARGEUR_TABLEAU, hauteur_grille/HAUTEUR_TABLEAU, images[11]->donneesRGB);
    //         }
    //         // else if (grille->cases[y * grille->largeur + x].estMarquee) {
    //         //     ecrisImage(posX, posY, images[9]->largeurImage, images[9]->hauteurImage, images[9]->donneesRGB);
    //         // }
    //     }
    // }
}

void gestionEvenement(EvenementGfx evenement) {
    static Grille grille = {LARGEUR_TABLEAU, HAUTEUR_TABLEAU, NULL};

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
                int x = abscisseSouris() / (LARGEUR_GRILLE/LARGEUR_TABLEAU);
                int y = ordonneeSouris() / (HAUTEUR_GRILLE/HAUTEUR_TABLEAU);
                reveleCase(&grille, x, y);
            } else if (etatBoutonSouris() == DroiteAppuye) {
                int x = abscisseSouris() / (LARGEUR_GRILLE/LARGEUR_TABLEAU);
                int y = ordonneeSouris() / (HAUTEUR_GRILLE/HAUTEUR_TABLEAU);
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
                // Logique fin du jeu
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


