#include "./ecs.hpp"
#include <memory>

void ECSManager::populateIdQueue() {
	for (int i = 0; i < MAX_ENTITIES; ++i) {
		this->availableIDs.push(i);
	}
}

void ECSManager::initSystems()
{
	/*systems.push_back(std::make_unique<RenderSystem>());*/
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
	/*for (int i = 0; i < systems.size(); i++) {
		if (systems[i] == NULL) {
			continue;
		}
		systems[i]->tick(entities);
	}*/
}
