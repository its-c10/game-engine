#include "entity.hpp"
#include "./component/i_component.hpp";

void Entity<IComponent>::addComponent(IComponent* comp) {
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