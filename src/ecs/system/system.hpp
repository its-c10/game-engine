#include "../ecs.hpp";
class System {
	virtual void tick(std::vector<EntitySPtr> entities) { return; };
};