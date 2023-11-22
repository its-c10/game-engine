#include <stdio.h>
#include <SDL.h>

/* Window constants */
#define WIDTH 800
#define HEIGHT 600
#define DELAY 3000

int main(int argc, char* args[]){

	SDL_Window* window = NULL;
	
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "SDL failed to initialise: %s\n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Tengine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WIDTH, HEIGHT, 0);

	if (window == NULL) {
		fprintf(stderr, "SDL window failed to initialise: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Delay(DELAY);

	/* Frees memory */
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}