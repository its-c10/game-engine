#include <SDL.h>
#include "fps_tracker.hpp"
class Tengine {
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	double last_time;
	int fps;
	FPS_Tracker fps_tracker;
	public:
		void setup();
		void update();
		void render();
		void process_input();
		void shutdown();
		bool is_running();
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
		FPS_Tracker getFPSTracker();
		Tengine();
};