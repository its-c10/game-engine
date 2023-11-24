#include <iostream>
#include "entity.hpp"

double Entity::getY() {
	return y;
}

double Entity::getX() {
	return x;
}

void Entity::render() {
	
}

bool Entity::should_render() {
	return true;
}
