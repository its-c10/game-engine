#include "./system.hpp";
class RenderSystem : System {
	void tick(std::vector<EntitySPtr> entities) override;
};