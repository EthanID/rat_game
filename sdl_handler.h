bool initSDL(SDL_Window **window, SDL_Surface **screenSurface, int SCREEN_WIDTH, int SCREEN_HEIGHT);
bool loadMediaSDL(SDL_Surface **mediaSurface, char* mediaURL, SDL_Surface **screenSurface);
void closeSDL(SDL_Window **window);
