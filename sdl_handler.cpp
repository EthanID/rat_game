#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

bool initSDL(SDL_Window **window, SDL_Surface **screenSurface, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
	cerr << "SDL could not initialize, fool! SDL_Error: " << SDL_GetError() << endl;
	return false;
    } else {
	*window = SDL_CreateWindow("Rat Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if(*window == NULL) {
	    cerr << "Window could not be created, fool! SDL_Error: " << SDL_GetError() << endl;
	    return false;
	} else {
	    int imgFlags = IMG_INIT_PNG;
	    if(!(IMG_Init(imgFlags) & imgFlags)) {
		cerr << "SDL_image could not initialize! SDL_ImageError: " << IMG_GetError();
		return false;
	    } else {
		*screenSurface = SDL_GetWindowSurface(*window);
		return true;
	    }
	}
    }
}

bool loadMediaSDL(SDL_Surface **mediaSurface, char* mediaURL, SDL_Surface **screenSurface) {
    SDL_Surface *unoptimizedSurface = IMG_Load(mediaURL);
    if(unoptimizedSurface == NULL) {
	cerr << "Could not load image " << mediaURL << "! SDL_Error: " << SDL_GetError() << endl;
	return false;
    } else {
	*mediaSurface = SDL_ConvertSurface(unoptimizedSurface, (*screenSurface)->format, 0);
	SDL_FreeSurface(unoptimizedSurface);
	if(*mediaSurface == NULL) {
	    cerr << "Could not optimize image " << mediaURL << "! SDL_Error: " << SDL_GetError() << endl;
	    return false;
	}
    }
    return true;
}

void closeSDL(SDL_Window **window) {
    SDL_DestroyWindow(*window);
    *window = nullptr;
    SDL_Quit();
}
