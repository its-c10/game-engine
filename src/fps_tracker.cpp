#include <iostream>
#include "fps_tracker.hpp";
#include <SDL.h>

FPS_Tracker::FPS_Tracker() {
	last_time_stamp = SDL_GetTicks64();
}

void FPS_Tracker::handle_frames() {
	fps++;
	double curr_ticks = SDL_GetTicks64();
	double diff_in_seconds = (curr_ticks - last_time_stamp) / 1000.0;
	if (diff_in_seconds < 1) { // only want to tick if it's been a second;
		return;
	}
	last_time_stamp = SDL_GetTicks64();
	std::cout << "FPS: " << last_fps << "\n\n";
	last_fps = fps;
	fps = 0;
}