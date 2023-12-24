#include <cstdint>
#ifndef _ICOMPONENT_
#define _ICOMPONENT_

enum ComponentType {
	NONE = -1,
	SPRITE = 0,
	TRANSFORM = 1
};

struct IComponent {
	virtual ComponentType type();
};

#endif