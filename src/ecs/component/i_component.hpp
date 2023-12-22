#include <cstdint>
#ifndef _ICOMPONENT_
#define _ICOMPONENT_
struct IComponent {
	virtual ComponentType type();
};

enum ComponentType {
	NONE = -1,
	SPRITE = 0,
	TRANSFORM = 1
};

#endif