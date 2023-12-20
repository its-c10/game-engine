#include "./ecs.hpp"
#include "../constants.h"
#include <memory>

ECSManager::ECSManager() {
	this->populateIdQueue();
}

void ECSManager::populateIdQueue() {
	for (int i = 0; i < MAX_ENTITIES; ++i) {
		this->availableIDs.push(i);
	}
}

EntityID ECSManager::getEntityId() {
	int id = this->availableIDs.front();
	this->availableIDs.pop();
	return id;
}

std::shared_ptr<Entity<IComponent>> ECSManager::createEntity() {
	EntityID id = this->getEntityId();
	std::shared_ptr<Entity<IComponent>> entity = std::make_shared<Entity<IComponent>>(id);
	return entity;
}

void ECSManager::destroyEntity(EntityID id)
{
}
