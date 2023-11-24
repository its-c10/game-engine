#include <iostream>
#include "tengine.hpp"
#include "constants.h"
#include <SDL.h>

bool Tengine::is_running() { return running; }

SDL_Window* Tengine::getWindow() { return window; }

SDL_Renderer* Tengine::getRenderer() { return renderer; }

void Tengine::setup() {

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL failed to initialize. Error code: " << SDL_GetError();
		return;
	}

	window = SDL_CreateWindow("Tengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	if (!window) {
		std::cout << "SDL window failed to initialize. Eror code: " << SDL_GetError();
		return;
	}

	/* -1 = default display driver */
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cout << "SDL renderer failed to initialize. Error code: " << SDL_GetError();
		return;
	}

	running = true;

}

Tengine::Tengine() {
	setup();
}

void Tengine::update() {

}

void Tengine::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set draw color
	SDL_RenderClear(renderer); // Clear render context

	// Render things into back buffer before swap.
	SDL_Rect rect = { 10, 10, 30, 30 };

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &rect);

	/*
		renders via double buffer
		front buffer contains things that you see
		back buffer contains things that we need to render in next frame
		it swaps front and back buffer repeatedly.
	*/
	SDL_RenderPresent(renderer); // The buffer swap
}

void Tengine::process_input() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		running = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			running = false;
		}
		break;

	}
}

void Tengine::shutdown() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}