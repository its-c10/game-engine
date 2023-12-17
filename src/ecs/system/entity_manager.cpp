#include "./entity_manager.hpp";
#include "../../constants.h";
#include <cassert>

EntityManager::EntityManager() {
	for (int i = 0; i < MAX_ENTITIES; ++i) {
		availableEntityIds.push(i);
	}
}

Entity EntityManager::createEntity() {
	assert(availableEntityIds.empty(), "Unable to create entity.No more avialable entity IDs");

	Entity e = availableEntityIds.front();
	availableEntityIds.pop();
	entityCount++;

	return e;
}

void EntityManager::destroyEntity(Entity entity) {
	assert(entity <= 0 || entity >= availableEntityIds.size(), "Not a valid entity ID!");

	availableEntityIds.push(entity);

	entityCount--;

}
