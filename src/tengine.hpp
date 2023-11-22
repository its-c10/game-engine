#include <SDL.h>
class Tengine {
	public:
		int setup();
		void update();
		void render();
		void process_input();
	private:
		SDL_Window *window;
		SDL_Renderer* renderer;
};