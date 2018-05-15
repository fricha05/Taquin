#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "plateau.h"
#include "graphics.h"
#include "control.h"

int main(int argc, char *argv[])
{
	Plateau P;
	createWindow();
	MLV_Image* image = MLV_load_image("pic.jpg");
	InitialisationPlateau(&P);
	Shuffle(&P);
	
	displayFullImage(image);
	MLV_wait_seconds(3);
	displayShuffledImage(&P, image);
	while(isComplete(&P) == 0){
		actions(&P, image, getKey());
	}
	displayFullImage(image);
	MLV_wait_seconds(1);
	MLV_draw_adapted_text_box(120, 200, "Bravo, vous avez gagné !", 50, MLV_COLOR_BLACK, MLV_COLOR_RED, MLV_COLOR_WHITE, MLV_TEXT_CENTER);
	MLV_actualise_window();
	MLV_wait_seconds(5);
	return 0;
}