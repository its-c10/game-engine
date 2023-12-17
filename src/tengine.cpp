#include <iostream>
#include "tengine.hpp"
#include "constants.h"
#include <SDL.h>
#include <chrono>

float y, x;

FPS_Tracker Tengine::getFPSTracker() { return fps_tracker; };

bool Tengine::is_running() { return running; }

SDL_Window* Tengine::getWindow() { return window; }

SDL_Renderer* Tengine::getRenderer() { return renderer; }

uint64_t time_in_millis() {
	using namespace std::chrono;
	return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void Tengine::setup() {

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL failed to initialize. Error code: " << SDL_GetError() << "\n";
		return;
	}

	window = SDL_CreateWindow("Tengine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

	if (!window) {
		std::cout << "SDL window failed to initialize. Eror code: " << SDL_GetError() << "\n";
		return;
	}
	std::cout << "Window initialized!\n";

	/* -1 = default display driver */
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cout << "SDL renderer failed to initialize. Error code: " << SDL_GetError() << "\n";
		return;
	}
	std::cout << "Renderer initialized!\n";

	running = true;
	std::cout << "Setup complete!\n";

}

Tengine::Tengine() {
	setup();
	last_time = SDL_GetTicks64();
	fps_tracker = FPS_Tracker();
	x = 100;
	y = 100;
}

void Tengine::update() {

	// Delay the execution until we reach the target frame time in ms
	//int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - last_time); // UNCOMMENT THIS TO CAP FRAMES

	// Delay if we are too fast to process this frame.
	//if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) { // UNCOMMENT THIS TO CAP FRAMES
	//	SDL_Delay(time_to_wait);
	//}

	float delta_time = (SDL_GetTicks() - last_time) / 1000.0f; // Amount of time elapsed since last frame.
	x += (70.0f * delta_time); // move rectangle a certain amount of pixels per seconds.
	y += (20.0f * delta_time);
	//std::cout << "y: " << y << "\n";
	//std::cout << "x: " << x << "\n";
	last_time = SDL_GetTicks64(); // time in ms

}

void Tengine::render() {
	SDL_RenderClear(renderer); // Clear render context
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Background window color
	/* RENDER BELOW */


	// Rectangle will be rendered in this color.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	/* RENDER ABOVE */
	// front buffer contains things that you see renders via double buffer back buffer contains things that we need to render in next frameit swaps front and back buffer repeatedly.
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
