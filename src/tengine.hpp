#include <SDL.h>
#include "fps_tracker.hpp";
#include "./ecs/ecs.hpp";
class Tengine {
	FPS_Tracker fpsTracker;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::shared_ptr<ECSManager> ecsManager;
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
		FPS_Tracker getFPSTracker();
		Tengine();
};