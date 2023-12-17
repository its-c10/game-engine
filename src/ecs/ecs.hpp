#include <bitset>
#include "../constants.h";
#include "./component/transform.hpp";
#include "./component/sprite.hpp";
#include <unordered_map>

// entity id that can be unsigned 32 bit integer.
using Entity = std::uint32_t;

class ECSManager {
	// Components
	std::unordered_map<Entity, Transform> transforms;
	std::unordered_map<Entity, Sprite> sprites;
	//Systems
	
};