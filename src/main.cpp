#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "tengine.hpp"
#include "constants.h"

int is_running = false;
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

bool init_window() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL failed to initialize. Erro code: " << SDL_GetError();
		return false;
	}

	window = SDL_CreateWindow("Tengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	if (!window) {
		std::cout << "SDL window failed to initialize. Eror code: " << SDL_GetError();
		return false;
	}

	/* -1 = default display driver */
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cout << "SDL renderer failed to initialize. Error code: " << SDL_GetError();
		return false;
	}
}

void render() {

}

void setup() {

}

void update() {

}

void process_input() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_QUIT:
			is_running = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				is_running = false;
			}
			break;

	}

}

void shutdown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char *args[]){

	is_running = init_window();
	while (is_running) {
		process_input();
		update();
		render();
	}

	shutdown();

	/*SDL_Delay(DELAY);
	SDL_DestroyWindow(window);
	SDL_Quit();*/

	return 0;
}