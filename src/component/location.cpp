#include "location.hpp";

Location::Location(int x, int y) {
	this->x = x;
	this->y = y;
}

int Location::getX() {
	return x;
}

int Location::getY() {
	return y;
}