#include "./ecs.hpp"
#include <memory>

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

ECSManager::ECSManager()
{
	this->populateIdQueue();
}

EntitySPtr ECSManager::createEntity() {
	EntityID id = this->getEntityId();
	EntitySPtr entity = std::make_shared<Entity<IComponent>>(id);
	entities.push_back(entity);
	return entity;
}

void ECSManager::destroyEntity(EntityID id)
{
}

void ECSManager::tickSystems()
{
	
}
