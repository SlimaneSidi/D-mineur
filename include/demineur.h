#ifndef DEMINEUR_H
#define DEMINEUR_H

#include "../gfxlib/include/GfxLib.h"
#include "../gfxlib/include/BmpLib.h"

#define LARGEUR_FENETRE 800
#define HAUTEUR_FENETRE 600
#define LARGEUR_TABLEAU 10
#define HAUTEUR_TABLEAU 15
#define LARGEUR_GRILLE ((LARGEUR_FENETRE*9/10)-(LARGEUR_FENETRE/4))
#define HAUTEUR_GRILLE ((HAUTEUR_FENETRE*9/10)-(HAUTEUR_FENETRE/6))
#define NB_IMAGES 12  // 8 chiffres, 1 drapeau, 1 mine, 1 case vide

typedef struct {
    bool estRevelee;
    bool estMine;
    bool estMarquee;
    int nbMines;  // Nombre de mines adjacentes
} cell;

typedef struct {
    int largeur;
    int hauteur;
    cell *cases;
} Grille;

void gestionEvenement(EvenementGfx evenement);
void initialiseGrille(Grille *grille);
void dessineJeu(Grille *grille);
void dessineGrille(Grille *grille);
void chargeImages(void);
void libereImages(void);
void reveleCase(Grille *grille, int x, int y);
void marqueDrapeau(Grille *grille, int x, int y);
int compterMinesAdjacentes(const Grille *grille, int x, int y);

#endif

