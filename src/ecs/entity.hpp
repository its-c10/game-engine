#include "./component/i_component.hpp";
#include "../constants.h";
#include <vector>
#include <array>

using EntityID = uint32_t;

template <typename IComponent>
class Entity {
	EntityID id;
	std::array<IComponent*, MAX_COMPONENTS> components;
	public:
		Entity(EntityID id);
		void addComponent(IComponent* comp);
		void removeComponent(IComponent* comp);
		void removeComponent(ComponentType type);
		EntityID getId();
};