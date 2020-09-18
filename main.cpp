#include <SDL2/SDL.h>
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
    loadMediaSDL(&rat, "images/rat.bmp");
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xAA, 0x11, 0x11));
    SDL_BlitSurface(rat, NULL, screenSurface, NULL);
    SDL_UpdateWindowSurface(window);
    SDL_FreeSurface(rat);
    SDL_Delay(9000);
    closeSDL(&window);
    return 0;
}
