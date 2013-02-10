#ifndef _FLOOF_H
#define _FLOOF_H

#include "GameObject.h"
#include "StaticObject.h"
#include <Box2D\Dynamics\b2Body.h>

class Floof: public GameObject
{
public:
	Floof(double x, double y, b2World& world);
	~Floof();

	void Render();

	virtual ColliderComponent* GetColliderComponent() {return new StaticObject(this);};

private:
	b2Body* mBody;
};

#endif