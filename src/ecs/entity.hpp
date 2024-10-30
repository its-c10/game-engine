#include "./component/i_component.hpp";
#include "../constants.h";
#include <vector>
#include <array>
#include<memory>

using EntityID = uint32_t;

template <typename IComponent>
class Entity {
	EntityID id;
	std::array<std::shared_ptr<IComponent>, MAX_COMPONENTS> components = { NULL };
	public:
		Entity(EntityID id);
		void addComponent(std::unique_ptr<IComponent>& comp);
		void removeComponent(IComponent* comp);
		void removeComponent(ComponentType type);
		std::unique_ptr<IComponent> getComponent(ComponentType type);
		bool hasComponent(ComponentType type);
		EntityID getId();
};
