#include "../include/demineur.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#define NB_IMAGES 12
#define TAILLE_CASE 32

static DonneesImageRGB* images[NB_IMAGES] = {0};  // Tableau pour stocker les images chargées
static int loose = 0;
DonneesImageRGB* compresseImage(DonneesImageRGB *image) {
    if (!image) {
        printf("Image NULL !!!\n");
        return NULL;
    }
    // int largeur_case = LARGEUR_GRILLE / LARGEUR_TABLEAU;
    // int hauteur_case = HAUTEUR_GRILLE / HAUTEUR_TABLEAU;
    int largeur_case = TAILLE_CASE;
    int hauteur_case = TAILLE_CASE;
    DonneesImageRGB* nimage = calloc(1, sizeof(DonneesImageRGB));

    nimage->largeurImage = largeur_case;
    nimage->hauteurImage = hauteur_case;
    nimage->donneesRGB = calloc(3 * largeur_case * hauteur_case, sizeof(char));

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
    char filename[20] = {0};
    for (int i = 0; i <= 8; i++) {
        sprintf(filename, "./BMP/%d.bmp", i);
        images[i] = compresseImage(lisBMPRGB(filename));
        //images[i] = lisBMPRGB(filename);
        if (!images[i]) {
            fprintf(stderr, "Failed to load image %s\n", filename);
        }
    }
    // Assure-toi que les images spéciales sont également chargées correctement.
    images[9] = compresseImage(lisBMPRGB("./BMP/drapeau.bmp"));
    if (!images[9]) {
        fprintf(stderr, "Failed to load image %s\n", "./BMP/drapeau.bmp");
    }
    images[10] = compresseImage(lisBMPRGB("./BMP/mine.bmp"));
    if (!images[10]) {
        fprintf(stderr, "Failed to load image %s\n", "./BMP/mine.bmp");
    }
    images[11] = compresseImage(lisBMPRGB("./BMP/case.bmp"));
    if (!images[11]) {
        fprintf(stderr, "Failed to load image %s\n", "./BMP/case.bmp");
    }
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
    grille->cases = calloc(grille->largeur * grille->hauteur, sizeof(cell));
    for (int y = 0; y < grille->hauteur; y++) {
        for (int x = 0; x < grille->largeur; x++) {
            grille->cases[y * grille->largeur + x] = (cell){false, rand() % 6 == 0, false, 0}; // Initialiser nbMines à 0 ou autre logique appropriée
        }
    }
}




void dessineJeu(Grille *grille) {
    effaceFenetre(128, 128, 128);
    couleurCourante(96, 96, 96);
    epaisseurDeTrait(2);
    rectangle(largeurFenetre() / 3, hauteurFenetre() / 6, largeurFenetre() * 2/3, hauteurFenetre() * 9 / 10);
    dessineGrille(grille);
    if(loose == 1){
        couleurCourante(255, 0, 0);
        rectangle(0, 0, 1920, 1080);
        couleurCourante(0, 0, 0);
        afficheChaine("Perdu BOUFFON", 50, largeurFenetre()/3, hauteurFenetre()/2);

    }
}

 void dessineGrille(Grille *grille) {
    //int largeur_grille = (largeurFenetre() * 9 / 10) - (largeurFenetre() / 4);
    //int hauteur_grille = (hauteurFenetre() * 9 / 10) - (hauteurFenetre() / 6);
     for (int y = 0; y < grille->hauteur; y++) {
         for (int x = 0; x < grille->largeur; x++) {
            // int posX = x * (largeur_grille / LARGEUR_TABLEAU) + largeurFenetre() / 4;
            // int posY = y * (hauteur_grille / HAUTEUR_TABLEAU) + hauteurFenetre(
            int index = 11;  // Index par défaut pour une case non révélée
            if (grille->cases[y * grille->largeur + x].estRevelee) {
                index = grille->cases[y * grille->largeur + x].estMine ? 10 : grille->cases[y * grille->largeur + x].nbMines;
                //if (index > 4) index = 11; // S'assurer que l'index reste valide
            } else if (grille->cases[y * grille->largeur + x].estMarquee) {
                index = 9;  // Index pour le drapeau
           }
            int posX = x*images[index]->largeurImage;
            int posY = y*images[index]->hauteurImage;
            ecrisImage(posX, posY, images[index]->largeurImage,images[index]->hauteurImage,images[index]->donneesRGB);
            //ecrisImage(posX+(largeurFenetre() / 3), (hauteurFenetre() / 6)+posY, images[index]->largeurImage,images[index]->hauteurImage,images[index]->donneesRGB);
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
            // ;int x = (abscisseSouris() - largeurFenetre() / 4) * LARGEUR_TABLEAU / largeurFenetre();
            // int y = (ordonneeSouris() - hauteurFenetre() / 6) * HAUTEUR_TABLEAU / hauteurFenetre();
            int x = abscisseSouris() / TAILLE_CASE;
            int y = ordonneeSouris() / TAILLE_CASE;
            if (etatBoutonSouris() == GaucheAppuye) {
                //peut etre remplacer x et y lors du centrage de a grille.
                reveleCase(&grille, x, y);
            } else if (etatBoutonSouris() == DroiteAppuye) {
                marqueDrapeau(&grille, x, y);
            }
            break;
        default:
            break;
    }
}

void reveleCase(Grille *grille, int x, int y) {
    cell *c = &grille->cases[y * grille->largeur + x];
    // if (!c->estRevelee && !c->estMarquee)
    {
        c->estRevelee = true;
        printf("%d\n",c->estMine);
         if (c->estMine) {
            loose += 1;
            printf("loose : %d\n",loose);
         }
        
        int adjacentMines = compterMinesAdjacentes(grille, x, y);
        if (adjacentMines == 0) {
            // Révéler récursivement les cases adjacentes sans mines
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx != 0 || dy != 0) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx >= 0 && nx < grille->largeur && ny >= 0 && ny < grille->hauteur && !grille->cases[ny * grille->largeur + nx].estRevelee) {
                            reveleCase(grille, nx, ny);
                        }
                    }
                }
            }
        }
        
    }
}


void marqueDrapeau(Grille *grille, int x, int y) {
    if (x >= 0 && x < grille->largeur && y >= 0 && y < grille->hauteur) {
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
            if (nx >= 0 && nx < grille->largeur && ny >= 0 && ny < grille->hauteur) {
                if (grille->cases[ny * grille->largeur + nx].estMine) {
                    count++;
                }
            }
        }
    }
    return count;
}

