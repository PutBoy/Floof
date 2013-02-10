#ifndef _NON_COLLIDABLE_H
#define _NON_COLLIDABLE_H
#include "ColliderComponent.h"

class NonCollidable: public ColliderComponent
{
public:
	NonCollidable(GameObject* object);

	void SetX(double x);
	void SetY(double y);

	void SetOtherX(double x, ColliderComponent* other);
	void SetOtherY(double y, ColliderComponent* other);
};

#endif