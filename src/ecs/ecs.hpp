#include <bitset>
#include "../constants.h";
#include "./component/transform.hpp";
#include "./component/sprite.hpp";
#include "./entity.hpp";
#include <queue>
#include <unordered_map>
#include <memory>

using EntitySPtr = std::shared_ptr<Entity<IComponent>>;
class ECSManager {
	std::vector<EntitySPtr> entities;
	std::queue<EntityID> availableIDs;
	public:
		ECSManager();
		EntitySPtr createEntity();
		void destroyEntity(EntityID id);
		void tickSystems();
	private:
		EntityID getEntityId();
		void populateIdQueue();
};

