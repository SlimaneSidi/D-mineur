#ifndef DEMINEUR_H
#define DEMINEUR_H

#include "../gfxlib/include/GfxLib.h"
#include "../gfxlib/include/BmpLib.h"

#define LARGEUR 10
#define HAUTEUR 15
#define TAILLE_CASE 40
#define NB_IMAGES 11  // 8 chiffres, 1 drapeau, 1 mine, 1 case vide

typedef struct {
    bool estMine;
    bool estRevelee;
    bool estMarquee;
} Case;

typedef struct {
    int largeur;
    int longueur;
    Case *cases;
} Grille;

extern DonneesImageRGB *images[NB_IMAGES];

void gestionEvenement(EvenementGfx evenement);
void initialiseGrille(Grille *grille);
void dessineGrille(const Grille *grille);
void chargeImages(void);
void libereImages(void);
void reveleCase(Grille *grille, int x, int y);
void marqueDrapeau(Grille *grille, int x, int y);
int compterMinesAdjacentes(Grille *grille, int x, int y);

#endif

