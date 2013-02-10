#ifndef _STATIC_OBJECT_H
#define _STATIC_OBJECT_H
#include "ColliderComponent.h"

class StaticObject:public ColliderComponent
{
public:
	StaticObject(GameObject* object);
	virtual ~StaticObject(){}

	void SetX(double x){};
	void SetY(double y){};

	//Ändrat
	void SetOtherX(double x, ColliderComponent* other);
	void SetOtherY(double y, ColliderComponent* other);
};

#endif