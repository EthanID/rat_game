#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "sdl_handler.h"

using namespace std;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main(int argc, char* args[]) {
    SDL_Window *window = nullptr;
    SDL_Surface *screenSurface = nullptr;

    initSDL(&window, &screenSurface, SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface *rat = nullptr;
    loadMediaSDL(&rat, "images/swiss_cheese.png", &screenSurface);

    bool quit = false;
    SDL_Event event;
    while(!quit) {
	while(SDL_PollEvent(&event) != 0 ) {
	    if(event.type == SDL_QUIT) {
		quit = true;
	    }
	    else if(event.type == SDL_KEYDOWN) {
		switch(event.key.keysym.sym) {
		    case SDLK_UP:
			cout << "up" << endl;
			break;
		    case SDLK_DOWN:
			cout << "down" << endl;
			break;
		    case SDLK_LEFT:
			cout << "left" << endl;
			break;
		    case SDLK_RIGHT:
			cout << "right" << endl;
			break;
		}
	    }
	}
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xAA, 0x11, 0x11));
	SDL_Rect stretchRat;
	stretchRat.x = stretchRat.y = 100;
	stretchRat.w = 100;
	stretchRat.h = 100;
	SDL_BlitScaled(rat, NULL, screenSurface, &stretchRat);
	SDL_UpdateWindowSurface(window);
    }

    SDL_FreeSurface(rat);
    closeSDL(&window);
    return 0;
}
