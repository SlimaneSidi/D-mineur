int main(void)
{
	// A faire: utiliser la fonction boucleEvenement() ici.

	int epoque = 0;
	printf("||---------------------------------------------||\n");
	printf("||------------┬ ┬┌─┐┬  ┌─┐┌─┐┌┬┐┌─┐------------||\n");
	printf("||------------│││├┤ │  │  │ ││││├┤ ------------||\n");
	printf("||------------└┴┘└─┘┴─┘└─┘└─┘┴ ┴└─┘------------||\n");
	printf("||---------------------------------------------||\n");
	printf(" \n");                                                
	printf("         Choisissez le nombre d'époques:         \n");
	printf(" \n");
	scanf("%d", & epoque);
	boucleEvenement(epoque);

	return 0;
}

void effaceConsole(void)
{
	if (system("clear") != 0) {
		printf("La console n'a pas pu être effacée...\n");
	}
}

// Attendre 'duree' secondes avant de continuer.
void attendre(double duree)
{
	// usleep() permet d'attendre un nombre entier de micro-secondes,
	// a contrario de sleep() qui n'attend qu'un nombre de secondes:
	usleep(duree * 1000000.);
}

// A faire: implémenter les autres fonctions en suivant les prototypes ci-dessus.

int saisieChoixInit(void){
	int choix = 0;
	printf("||---------------------------------------------||\n");
	printf("||------- ┬┌─┐┬ ┬ ┌┬┐┌─┐ ┬  ┌─┐ ┬  ┬┬┌─┐-------||\n");
	printf("||------- │├┤ │ │  ││├┤  │  ├─┤ └┐┌┘│├┤ -------||\n"); 
	printf("||-------└┘└─┘└─┘ ─┴┘└─┘ ┴─┘┴ ┴  └┘ ┴└─┘-------||\n");
	printf("||---------------------------------------------||\n");
	printf("\n");
	printf("||---------------------------------------------||\n");
	printf("||------------CONFIGURATION INITALE------------||\n");
	printf("||---------------------------------------------||\n");
	printf("||----------0 - Clignotant / Blinker-----------||\n");
	printf("||------------1 - Grenouille / Toad------------||\n");
	printf("||--------------2 - Phare / Beacon-------------||\n");
	printf("||------------3 - Planeur / Glider-------------||\n");
	printf("||---------------4 - R-pentomino---------------||\n");
	printf("||-------------5 - Pentadecathlon--------------||\n");
	printf("||---------6 - Configuration aléatoire---------||\n");
	printf("||-----------------7 - Quitter-----------------||\n");
	printf("||---------------------------------------------||\n");
	printf("\n");
	scanf("%d", &choix);
	printf("\n");
	return choix;
}

int saisieTypePavage(void){
	int choix = 0;
	printf("||---------------------------------------------||\n");
	printf("||-----------------TYPE PAVAGE-----------------||\n");
	printf("||---------------------------------------------||\n");
	printf("||--------0 - Voisinage carré standard---------||\n");
	printf("||-----------1 - Voisinage hexagonal-----------||\n");
	printf("||------------------2 - Retour-----------------||\n");
	printf("||-----------------3 - Quitter-----------------||\n");
	printf("||---------------------------------------------||\n");
	printf("\n");
	scanf("%d", &choix);
	printf("\n");
	return choix;
}