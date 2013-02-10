#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"
#include "NonCollidable.h"

class Bullet: public GameObject
{
public:
	Bullet(int x, int y, double speed, sf::Vector2f targetDirection, b2World& world);

	ColliderComponent* GetColliderComponent(){return new NonCollidable(this);};

	void Update();
	void Render();
};

#endif