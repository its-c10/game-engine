#include "./i_component.hpp";
#include <SDL_render.h>
struct Sprite : IComponent {
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture* texture;
	ComponentType type() { 
		return SPRITE;
	}
};