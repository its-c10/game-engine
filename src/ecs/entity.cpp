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

EntityID Entity<IComponent>::getId() {
	return this->id;
}

