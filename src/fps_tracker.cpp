#include <iostream>
#include "fps_tracker.hpp";
#include <SDL.h>

FPSTracker::FPSTracker() {
	lastTimeStamp = SDL_GetTicks64();
}

void FPSTracker::handleFrames() {
	fps++;
	double curr_ticks = SDL_GetTicks64();
	double diff_in_seconds = (curr_ticks - lastTimeStamp) / 1000.0;
	if (diff_in_seconds < 1) { // only want to update frames if it's been a second;
		return;
	}
	lastTimeStamp = SDL_GetTicks64();
	lastFps = fps;
	fps = 0;
	std::cout << "FPS: " << lastFps << "\n\n";
}

