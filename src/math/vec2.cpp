#include "Vec2.hpp"

Vec2::Vec2() {
	this->x = 0;
	this->y = 0;
}

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

float Vec2::getX() {
	return this->x;
}

float Vec2::getY() {
	return this->y;
}

float Vec2::dot(Vec2 vec) {
	return 0;
}

Vec2 Vec2::add(Vec2 vec) {
	return vec;
}