#ifndef _FLOOF_H
#define _FLOOF_H

#include "GameObject.h"
#include "StaticObject.h"

class Floof: public GameObject
{
public:
	Floof(int x, int y);

	void Render();

	virtual ColliderComponent* GetColliderComponent() {return new StaticObject(this);};
};

#endif