#include <bitset>
#include "../constants.h";
#include "./component/transform.hpp";
#include "./component/sprite.hpp";
#include "./entity.hpp";
#include <queue>
#include <unordered_map>

class ECSManager {
	std::vector<Entity<IComponent>> entities;
	std::queue<EntityID> availableIDs;
	public:
		ECSManager();
		std::shared_ptr<Entity<IComponent>> createEntity();
		void destroyEntity(EntityID id);
	private:
		EntityID getEntityId();
		void populateIdQueue();
};

