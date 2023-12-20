#include <cstdint>
using ComponentType = std::uint8_t;
struct IComponent {
	virtual ComponentType type();
};