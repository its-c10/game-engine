#ifndef _TRANSFORM_
#define _TRANSFORM_

#include "../../math/vec2.hpp";
#include "./i_component.hpp";
struct Transform : IComponent {
	Vec2 position; // origin
	Vec2 rotation; // basis
	ComponentType type() { return 0; }
};

#endif