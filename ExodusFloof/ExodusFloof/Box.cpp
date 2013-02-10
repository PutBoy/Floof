#include "Box.h"
#include <cmath>
#include "SimpleImageJob.h"

Box::Box(int x, int y, int gravity):
	GameObject(x, y, 0.2),
	gravityModifier(gravity)
{

	SetSizeY(62);
	SetSizeX(62);
	SetID("Box");

}

void Box::Render()
{
	GetCanvas()->AddNewJob(new SimpleImageJob("Box", GetX() - 32, GetY() - 32), 0);
}

void Box::Update(){

	SetVelocityY(GetVelocityY() + 0.1 * gravityModifier);

	GameObject::Update();
}

void Box::ReverseGravity(){
	gravityModifier = -gravityModifier;
}
