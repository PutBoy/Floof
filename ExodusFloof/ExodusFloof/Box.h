#ifndef BOX_H
#define BOX_H
#include "GameObject.h"
#include "Trigonometry.h"
#include "Collidable.h"

class Box:public GameObject{
public:
	Box(double x, double y,int gravity);
	void Update();
	void Render();

 	void ReverseGravity();

	ColliderComponent* GetColliderComponent(){return new Collidable(this);};
private:
	Trigonometry trigonometry;
	int gravityModifier;
};


#endif