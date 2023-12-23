#include "../ecs.hpp";
using SystemPtr = std::unique_ptr<System>;
class System {
	virtual void tick(std::vector<EntitySPtr> entities) { return; };
};