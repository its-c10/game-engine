#include <bitset>
#include "../constants.h";
#include "./component/transform.hpp";
#include "./component/sprite.hpp";
#include "./entity.hpp";
#include <queue>
#include <unordered_map>
#include <memory>

using EntitySPtr = std::shared_ptr<Entity<IComponent>>;
class System {
	public:
		virtual void tick(std::vector<EntitySPtr> entities) { return; };
};
using SystemPtr = std::unique_ptr<System>;

class RenderSystem : public System {
	public:
		void tick(std::vector<EntitySPtr> entities) override;
};

class ECSManager {
	
public:
	ECSManager();
	EntitySPtr createEntity();
	void destroyEntity(EntityID id);
	void tickSystems();
private:
	std::vector<EntitySPtr> entities;
	std::queue<EntityID> availableIDs;
	std::vector<SystemPtr> systems = { NULL };
	EntityID getEntityId();
	void populateIdQueue();
	void initSystems();
};
