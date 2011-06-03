#include "SDLStage.h"


SDLStage::SDLStage (int width, int height, int frameRate) {
	
	if (SDL_Init (SDL_INIT_VIDEO | SDL_INIT_TIMER) == 0) {
		
		screen = SDL_SetVideoMode (width, height, 0, 0);
		
		if (screen != NULL) {
			
			previousTime = 0;
			ticksPerFrame = (int)(1000 / frameRate);
			active = true;
			paused = false;
			
		} else {
			
			cerr << "Could not set video mode: " << SDL_GetError () << endl;
				
		}
		
	} else {
		
		cerr << "Could not initialize SDL: " << SDL_GetError () << endl;
		
	}
	
}


SDLStage::~SDLStage () {
	
  	SDL_Quit ();
	
}


void SDLStage::handleEvent (SDL_Event &event) {
	
	switch (event.type) {
		
		case SDL_ACTIVEEVENT:
			
			if (event.active.state & SDL_APPACTIVE) {
				
				if (event.active.gain == 0) {
				
					//paused = true;
				
				} else {
				
					//paused = false;
				
				}
			
			}
			
			break;
		
		case SDL_VIDEOEXPOSE:
			
			render ();
			
			break;
		
		case SDL_QUIT:
			
			active = false;
			
			break;
		
	}
	
	(*eventListener) (event);
	
	event.type = -1;
	
}


void SDLStage::render () {
	
	(*renderCallback) (screen);
	
}


void SDLStage::setCaption (string title) {
	
	if (active) {
		
		SDL_WM_SetCaption (title.c_str (), title.c_str ());
		
	}
	
}


void SDLStage::setEventListener (void (*listener) (SDL_Event&)) {
	
	eventListener = listener;
	
}


void SDLStage::setRenderCallback (void (*callback) (SDL_Surface*)) {
	
	renderCallback = callback;
	
}


void SDLStage::setUpdateCallback (void (*callback) (int)) {
	
	updateCallback = callback;
	
}


void SDLStage::step () {
	
	SDL_Event event;
	
	if (paused) {
		
		if (SDL_WaitEvent (&event)) {
			
			handleEvent (event);
			
		}
			
	} else {
		
		while (SDL_PollEvent (&event)) {
		
			handleEvent (event);
			
			if (!active) {
				
				break;
				
			}
		
		}
		
		if (active) {
			
			int currentTime = SDL_GetTicks ();
			int deltaTime = currentTime - previousTime;
			
			update (currentTime - previousTime);
			render ();
			
			while (deltaTime < ticksPerFrame) {
			
				SDL_TimerID timer = SDL_AddTimer (ticksPerFrame - deltaTime, timer_onComplete, NULL);
				
				SDL_WaitEvent (&event);
				SDL_RemoveTimer (timer);
			
				if (event.type != SDL_USEREVENT) {
				
					handleEvent (event);
					deltaTime = SDL_GetTicks () - previousTime;
				
				} else {
				
					event.type = -1;
					break;
				
				}
			
			}
			
			previousTime = currentTime;
	
		}
	
	}
	
}


void SDLStage::update (int deltaTime) {
	
	(*updateCallback) (deltaTime);
	
}




// Event Handlers




Uint32 timer_onComplete (Uint32 interval, void *param) {
	
	SDL_Event event;
	SDL_UserEvent userevent;

	userevent.type = SDL_USEREVENT;
	userevent.code = 0;
	userevent.data1 = NULL;
	userevent.data2 = NULL;

	event.type = SDL_USEREVENT;
	event.user = userevent;

	SDL_PushEvent (&event);

    return 0;
    
}
