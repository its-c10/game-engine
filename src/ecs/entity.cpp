#include "entity.hpp"

Entity<IComponent>::Entity(EntityID id) {
	this->id = id;
}

void Entity<IComponent>::addComponent(std::shared_ptr<IComponent> comp) {
	this->components[comp->type()] = comp;
}

void Entity<IComponent>::removeComponent(IComponent* comp) {
	this->components[comp->type()] = NULL;
}

void Entity<IComponent>::removeComponent(ComponentType type) {

}

std::shared_ptr<IComponent> Entity<IComponent>::getComponent(ComponentType type)
{
	return this->components[type];
}

bool Entity<IComponent>::hasComponent(ComponentType type)
{
	return this->components[type] != NULL;
}

EntityID Entity<IComponent>::getId() {
	return this->id;
}

