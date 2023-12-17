#include <SDL.h>
struct Sprite {
	SDL_Rect src;
	SDL_Rect dst;
	SDL_Texture* texture;
};