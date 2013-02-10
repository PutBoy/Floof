#ifndef _BORDER_H
#define _BORDER_H

#include "Display.h"
#include "GameObject.h"
#include "NonCollidable.h"

class Border:public GameObject
{
public:
	Border(/*FloofContainer* floors, */int y, bool right);
	void Render();
	void Update();

	ColliderComponent* GetColliderComponent() {return new NonCollidable(this);};
private:
	Display* display;
	bool mRight;
};

#endif