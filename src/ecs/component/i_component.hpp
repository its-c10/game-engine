#ifndef _ICOMPONENT_
#define _ICOMPONENT_
#include <cstdint>
using ComponentType = std::uint8_t;
struct IComponent {
	virtual ComponentType type();
};
#endif