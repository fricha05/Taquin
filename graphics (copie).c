#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "graphics.h"


/*Crée une fenêtre de taille 512*512 pixels*/
void createWindow(){
	MLV_create_window("Taquin", "Taquin", 512, 512);
}

/*Affiche la fenetre en entier et l'actualise*/
void displayFullImage(MLV_Image* image){
	MLV_draw_image(image, 0, 0);
	MLV_actualise_window();
}

/*Découpe l'image et mélange les morceaux en fonction des emplacements des carrés du plateau correspondants*/
void displayShuffledImage(Plateau* P, MLV_Image* image){
	int i;
	int j;
	for (i = 0; i < NB_LIG; ++i){
		for (j = 0; j < NB_COL; ++j){
			MLV_draw_partial_image(image, TAILLE_BLOC*(P->bloc[i][j].col), TAILLE_BLOC*(P->bloc[i][j].lig), TAILLE_BLOC, TAILLE_BLOC, j*TAILLE_BLOC, i*TAILLE_BLOC);
		}
	}
	MLV_draw_filled_rectangle(TAILLE_BLOC*P->noirY, TAILLE_BLOC*P->noirX, TAILLE_BLOC, TAILLE_BLOC, MLV_COLOR_BLACK);
	MLV_actualise_window();
}