#include "Box.h"
#include <cmath>
#include "SimpleImageJob.h"
#include "Collision.h"

Box::Box(double x, double y, int gravity):
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

	
	SetVelocityY(GetVelocityY() + 0.1 * static_cast<double>(gravityModifier));

	if (GetVelocityX() < 0)
	{
		SetVelocityX(GetVelocityX() + 0.5);
		if (GetVelocityX() > 0)
			SetVelocityX(0);
	}
	else if (GetVelocityX() > 0)
	{
		SetVelocityX(GetVelocityX() - 0.5);
		if (GetVelocityX() < 0)
			SetVelocityX(0);
	}

	GameObject::Update();

	Collision* collision = GetNextCollision();
	while (collision)
	{
		if (collision->GetGameObject()->IsID("Bullet"))
		{
			collision->GetGameObject()->Kill();
			ReverseGravity();
		}
		collision = GetNextCollision();
	}
}

void Box::ReverseGravity(){
	gravityModifier = -gravityModifier;
}
