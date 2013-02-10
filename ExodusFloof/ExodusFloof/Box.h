#ifndef BOX_H
#define BOX_H
#include "GameObject.h"
#include "Trigonometry.h"

class Box:public GameObject{
public:
	Box(int x, int y,int gravity);
	void Update();
	void Render();

 	void ReverseGravity();
	virtual void ResolveCollision(GameObject* other);
private:
	Trigonometry trigonometry;
	int gravityModifier;
};


#endif