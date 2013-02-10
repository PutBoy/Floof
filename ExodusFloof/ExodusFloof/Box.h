#ifndef BOX_H
#define BOX_H
#include "GameObject.h"
#include "Trigonometry.h"
#include "Collidable.h"

#include <Box2D\Dynamics\b2Body.h>

class Box:public GameObject{
public:
	Box(double x, double y,int gravity, b2World& world);
	~Box();
	void Update();
	void Render();

 	void ReverseGravity();

	ColliderComponent* GetColliderComponent(){return new Collidable(this);};
private:
	Trigonometry trigonometry;
	int gravityModifier;
	b2Body* mBody;
	
};


#endif