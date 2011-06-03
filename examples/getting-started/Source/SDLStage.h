#ifndef SDLSTAGE_H
#define SDLSTAGE_H


#include <iostream>
#include <string>
#include <SDL/SDL.h>


using namespace std;


class SDLStage {
	
	
	public:
		
		SDLStage (int width, int height, int frameRate);
		~SDLStage ();
		
		bool active;
		
		void setCaption (string title);
		void setEventListener (void (*listener) (SDL_Event&));
		void setRenderCallback (void (*callback) (SDL_Surface*));
		void setUpdateCallback (void (*callback) (int));
		void step ();
		
	
	private:
		
		void (*eventListener) (SDL_Event&);
		bool paused;
		int previousTime;
		void (*renderCallback) (SDL_Surface*);
		SDL_Surface* screen;
		int ticksPerFrame;
		void (*updateCallback) (int);
		
		void handleEvent (SDL_Event &event);
		void render ();
		void update (int deltaTime);
	
	
};


Uint32 timer_onComplete (Uint32 interval, void *param);


#endif
