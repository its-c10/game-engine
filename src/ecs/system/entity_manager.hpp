#include <iostream>
#include <queue>
#include "../ecs.hpp";
#include "../../constants.h";
class EntityManager {
	std::queue<Entity> availableEntityIds;
	int entityCount;
	public:
		EntityManager();
		Entity createEntity();
		void destroyEntity(Entity entity);
};