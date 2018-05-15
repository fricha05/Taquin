#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h> 
#include "control.h"
#include "plateau.h"
#include "graphics.h"

/*Récupère le code de la touche entrée et renvoie la chaine de caractère correspondante*/
char* getKey(){
	MLV_Keyboard_button key;
	MLV_Keyboard_modifier mod;
	int unicode;
	MLV_wait_keyboard(&key, &mod, &unicode);
	char* key_string;
	key_string = (char*)MLV_convert_keyboard_button_to_string(key);
	return key_string;
}

/*En fonction de la touche pressée, effectue l'action correspondante*/
void actions(Plateau* P, MLV_Image* image, char* key_string){
	char* keyup = "MLV_KEYBOARD_UP";
	char* keyright = "MLV_KEYBOARD_RIGHT";
	char* keydown = "MLV_KEYBOARD_DOWN";
	char* keyleft = "MLV_KEYBOARD_LEFT";
	int j,k;
	if(strcmp(key_string, keyup) == 0 && P->noirX > 0){
		moveUp(P);
		displayShuffledImage(P, image);
	}
	if(strcmp(key_string, keyright) == 0 && P->noirY < 3){
		moveRight(P);
		displayShuffledImage(P, image);
	}
	if(strcmp(key_string, keydown) == 0 && P->noirX < 3){
		moveDown(P);
		displayShuffledImage(P, image);
	}
	if(strcmp(key_string, keyleft) == 0 && P->noirY > 0){
		moveLeft(P);
		displayShuffledImage(P, image);
	}
	printf("La case noire [3,3] est à l'emplacement : [%d,%d]\n", (P->noirX), (P->noirY));
	for (j = 0; j < NB_LIG; ++j)
	{
		for (k = 0; k < NB_COL; ++k)
			{
				printf("[%d,%d] ", ((P->bloc)[j][k]).lig, ((P->bloc)[j][k]).col);
			}
		printf("\n");
	}
}

/*Echange la case noire avec celle du dessus*/
void moveUp(Plateau* P){
	swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX-1][P->noirY]));
	((P->noirX)-=1);
}

/*Echange la case noire avec celle de droite*/
void moveRight(Plateau* P){
	swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX][P->noirY+1]));
	((P->noirY)+=1);
}

/*Echange la case noire avec celle du dessous*/
void moveDown(Plateau* P){
	swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX+1][P->noirY]));	
	((P->noirX)+=1);
}

/*Echange la case noire avec celle de gauche*/
void moveLeft(Plateau* P){
	swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX][P->noirY-1]));
	((P->noirY)-=1);
}

/*Si la case noire est en bas à droite du plateau, vérifie la conformité de l'intégralité du plateau et renvoie 1 si il est complété, sinon renvoie 0*/
int verifPlateau(Plateau* P){
	int i;
	int j;
	for(i = 0; i < NB_LIG; i++){
		for (j = 0; j < NB_COL; j++)
		{
			if(((P->bloc)[i][j]).lig !=i || ((P->bloc)[i][j]).col !=j){
				return 0;
			}
		}
	}
	return 1;
}

/*Test si le plateau est complet, dès que la case noire est en bas à droite*/
int isComplete(Plateau *P){
	if((P->bloc)[NB_LIG-1][NB_COL-1].lig == NB_LIG-1 && (P->bloc)[NB_LIG-1][NB_COL-1].col == NB_COL-1){
		return verifPlateau(P);
	}
	return 0;
}
