#include "plateau.h"

int isComplete(Plateau* P);
int verifPlateau(Plateau* P);
char* getKey();
void actions(Plateau* P, MLV_Image* image, char* key_string);
void moveUp(Plateau* P);
void moveRight(Plateau* P);
void moveDown(Plateau* P);
void moveLeft(Plateau* P);