#include "SDLStage.h"


void handleEvent (SDL_Event &event) {
	
	
	
}


void render (SDL_Surface *screen) {
	
	Uint32 white = SDL_MapRGB (screen -> format, 0xFF, 0xFF, 0xFF);
	Uint32 red = SDL_MapRGB (screen -> format, 0xFF, 0x00, 0x00);

	SDL_FillRect (screen, NULL, white);
	
	SDL_Rect rect;
	rect.w = 100;
	rect.h = 100;
	rect.x = 10;
	rect.y = 10;
	
	SDL_FillRect (screen, &rect, red);
	
	SDL_Flip (screen);

}


void update (int deltaTime) {
	
	
	
}


int main (int argc, char** argv) {
	
	SDLStage* stage = new SDLStage (0, 0, 30);
	
	stage -> setCaption ("Getting Started");
	stage -> setEventListener (&handleEvent);
	stage -> setRenderCallback (&render);
	stage -> setUpdateCallback (&update);
	
	while (stage -> active) {
		
		stage -> step ();
		
	}
	
	delete stage;
	return 0;
	
}
