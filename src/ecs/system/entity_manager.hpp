#include <iostream>
#include <queue>
#include "../ecs.hpp";
#include "../../constants.h";
class EntityManager {
	std::queue<Entity> availableEntityIds;
	std::vector<Signature> signatures;
	int entityCount;
	public:
		EntityManager();
		Entity createEntity();
		void destroyEntity(Entity entity);
		void setSignature(Entity entity, Signature signature);
		Signature getSignature(Entity entity);
};