#ifndef _COLLIDABLE_H
#define _COLLIDABLE_H
#include "ColliderComponent.h"

class Collidable:public ColliderComponent
{
public:
	Collidable(GameObject* object);

	void SetX(double x);
	void SetY(double y);

	void SetOtherX(double x, ColliderComponent* other);
	void SetOtherY(double y, ColliderComponent* other);
};

#endif