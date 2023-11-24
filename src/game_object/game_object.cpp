#include <iostream>
#include "game_object.hpp"

double GameObject::getY() {
	return y;
}

double GameObject::getX() {
	return x;
}

void GameObject::render() {
	
}

bool GameObject::get_should_render() {
	return true;
}
