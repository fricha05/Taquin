#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "plateau.h"

/*Initialise le plateau de jeu dans le bon ordre*/
void InitialisationPlateau(Plateau* P){
	int i, j;

	for (i = 0; i < NB_LIG; ++i)
	{
		for (j = 0; j < NB_COL; ++j)
		{
			((P->bloc)[i][j]).lig = i;
			((P->bloc)[i][j]).col = j;
			printf("[%d,%d] ", i, j);
		}
		printf("\n");
	}
	P->noirX = 3;
	P->noirY = 3;
}

/*Permet d'échanger l'emplacement de deux blocs du plateau*/
void swapCarre(Carre *a, Carre *b){
	Carre tmp;
	tmp = (*a);
	(*a) = (*b);
	(*b) = tmp;
}

/*Mélange le plateau de jeu un nombre aléatoire de fois(entre 1000 et 2000 fois*/
void Shuffle(Plateau* P){
	int rnd, nbmelange, i, j, k;
	time_t t;
	srand((unsigned) time(&t));
	nbmelange = (rand() % (100 - 1000)) + 1000;
	for (i = 0; i < nbmelange; ++i)
	{
		rnd = rand() % 4;
		switch(rnd) {
			case 0:
				if((P->noirX) > 0){
					swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX-1][P->noirY]));
					((P->noirX)-=1);
				}
				break;
			case 1:
				if((P->noirY) < 3){
					swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX][P->noirY+1]));
					((P->noirY)+=1);
				}
				break;
			case 2:
				if((P->noirX) < 3){
					swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX+1][P->noirY]));	
					((P->noirX)+=1);	
				}
				break;
			default:
				if((P->noirY) > 0){
					swapCarre(&((P->bloc)[P->noirX][P->noirY]), &((P->bloc)[P->noirX][P->noirY-1]));
					((P->noirY)-=1);
				}
		}
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