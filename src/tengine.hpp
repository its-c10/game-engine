#include "../sdl/include/SDL.h"
#include "fps_tracker.hpp";
#include "./ecs/ecs.hpp";
class Tengine {
	FPSTracker fpsTracker;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::unique_ptr<ECSManager> ecsManager;
	double lastTime;
	int fps;
	bool running;
	public:
		void setup();
		void update();
		void render();
		void processInput();
		void shutdown();
		bool isRunning();
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
		FPSTracker& getFPSTracker();
		Tengine();
};
