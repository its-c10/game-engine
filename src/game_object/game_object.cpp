#include <iostream>
#include "game_object.hpp";

double GameObject::getY() {
	return y;
}

double GameObject::getX() {
	return x;
}

bool GameObject::should_render() {
	return should_render;
}


