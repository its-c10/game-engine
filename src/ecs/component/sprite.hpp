#include "./i_component.hpp";
#include "../../../sdl/include/SDL.h""
struct Sprite : IComponent {
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture* texture;
	ComponentType type() { 
		return SPRITE;
	}
};
