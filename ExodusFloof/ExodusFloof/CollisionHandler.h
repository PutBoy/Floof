#ifndef _COLLISION_HANDLER_H
#define _COLLISION_HANDLER_H
#include <vector>
#include <set>

class ColliderComponent;

class CollisionHandler
{
public:
	void Push(ColliderComponent* component);
	void Clear();

	void Collide();
	
private:
	bool TestCollision(ColliderComponent* c0, ColliderComponent* c1);
	void HandleCollision(ColliderComponent* c0, ColliderComponent* c1);
	
	std::vector<ColliderComponent*> mComponents;
};

#endif