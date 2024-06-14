#include "../include/main.h" 
#include "../../gfxlib/include/GfxLib.h" 
#include <GL/glut.h> // glutKeyboardUpFunc / glutget / GLUT_ELAPSED_TIME
#include "../include/ui.h"
#include "../include/outils.h"
#include "../include/opacite.h"
#include "../include/struct.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "pthread.h"
#include <stdbool.h>
#include <time.h>
#include <math.h>

//////////////////////////////  VARIABLES GLOBALES ///////////////////////////////////////////////

int screenHeight = 640; // Hauteur de la fenêtre
int screenWidth = 960; // Largeur de la fenêtre
static KeysStruct Keys = {0,0,0,0}; // Structure conservant l'état des touches
//static char Music[] = {"a-remplir.mp3"};


static int gameState = 0;

static int score= 0;
static int level = 1;

DonneesImageRGB *image = NULL; //////
int *pixels = NULL;
Texture2D *texture = NULL;

void ui() {
   

        bomb = lisBMPRGB("image/bomb.bmp");
        pixels = BVR2ARVB1(image->largeurImage, image->hauteurImage, image->donneesRGB);
        texture = creeTexture2D(image->largeurImage, image->hauteurImage, pixels);
        rectangleSelonTexture((screenWidth / 2) - 32, screenHeight / 8, texture);

    
   
        flag = lisBMPRGB("image/flag.bmp");
        pixels = BVR2ARVB1(image->largeurImage, image->hauteurImage, image->donneesRGB);
        texture = creeTexture2D(image->largeurImage, image->hauteurImage, pixels);
        rectangleSelonTexture((screenWidth / 2) - 32, screenHeight / 8, texture);

    

    
        interogation = lisBMPRGB("image/interogation.bmp");
        pixels = BVR2ARVB1(image->largeurImage, image->hauteurImage, image->donneesRGB);
        texture = creeTexture2D(image->largeurImage, image->hauteurImage, pixels);
        rectangleSelonTexture((screenWidth / 2) - 32, screenHeight / 8, texture);

      newHUD();
}




void newHUD() {
    char buffer[7] = {0};
    couleurCourante(100, 100, 100);
    rectangle(0, 0, screenWidth, screenHeight * 0.07);
    couleurCourante(0, 0, 128);

    rectangle(2, 0, screenWidth / 9 - 2, screenHeight * 0.07);

    rectangle(screenWidth / 9 + 2, 0, screenWidth / 3 - 2, screenHeight * 0.07);

    rectangle(screenWidth / 3 + 2, 0, 4 * screenWidth / 9 - 2, screenHeight * 0.07);

    rectangle(4 * screenWidth / 9 + 2, 0, 5 * screenWidth / 9 - 2, screenHeight * 0.07);

    rectangle(5 * screenWidth / 9 + 2, 0, 6 * screenWidth / 9 - 2, screenHeight * 0.07);

    rectangle(6 * screenWidth / 9 + 2, 0, 7 * screenWidth / 9 - 2, screenHeight * 0.07);

    rectangle(7 * screenWidth / 9 + 2, 0, screenWidth - 2, screenHeight * 0.07);

    // ecriture :
    couleurCourante(255, 255, 255);
    epaisseurDeTrait(3);
   
    afficheChaine("SCORE :", 20, screenWidth / 9 + 4, screenHeight * 0.045);
    sprintf(buffer, "%d", score);
    afficheChaine(buffer, 30, screenWidth / 6, screenHeight * 0.02);

}

void *loopThread(void *arg) {
    lanceBoucleEvenements();

    return NULL;
}
