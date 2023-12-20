#include "./i_component.hpp";
#include "../../../../../Other/SDL2/include/SDL_render.h"
struct Sprite : IComponent {
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture* texture;
	ComponentType type() { return 1; }
};