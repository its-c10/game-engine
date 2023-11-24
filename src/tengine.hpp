#include <SDL.h>
class Tengine {
	bool running;
	SDL_Window* window;
	SDL_Renderer* renderer;
	public:
		void setup();
		void update();
		void render();
		void process_input();
		void shutdown();
		bool is_running();
		SDL_Window* getWindow();
		SDL_Renderer* getRenderer();
		Tengine();
};