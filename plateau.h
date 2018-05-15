#ifndef _PLATEAU_
#define _PLATEAU_

#define NB_COL 4
#define NB_LIG 4
#define TAILLE_BLOC 128

typedef struct carre{
	int lig;
	int col;
}Carre;

typedef struct plateau{
	Carre bloc[NB_LIG][NB_COL];
	int noirX;
	int noirY;
}Plateau;

void InitialisationPlateau(Plateau* P);
void Shuffle(Plateau* P);
void swapCarre(Carre* a, Carre* b);

#endif