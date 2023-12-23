#include "render_system.hpp"
#include <iostream>

void RenderSystem::tick(std::vector<EntitySPtr> entities)
{
	for (EntitySPtr e : entities) {
		if (!e->hasComponent(ComponentType::SPRITE) || !e->hasComponent(ComponentType::TRANSFORM)) {
			continue;
		}
		std::shared_ptr<Transform> transform = std::static_pointer_cast<Transform>(e->getComponent(TRANSFORM));
		std::shared_ptr<Sprite> sprite = std::static_pointer_cast<Sprite>(e->getComponent(SPRITE));
		std::cout << "Transform Coords: [" << transform->position.getX() << transform->position.getY() << "]";
	}
}
