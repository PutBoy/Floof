#include "Box.h"
#include <cmath>
#include "SimpleImageJob.h"

Box::Box(int x, int y, int gravity):
	GameObject(x, y),
	gravityModifier(gravity)
{

	SetSizeY(64);
	SetSizeX(63);
	SetID("Box");

}

void Box::Render()
{
	GetCanvas()->AddNewJob(new SimpleImageJob("box", GetX(), GetY()), 0);
}
void Box::Update(){

	mVelocityY += 0.1 * gravityModifier;

	GameObject::Update();

}
void Box::ReverseGravity(){
	gravityModifier = -gravityModifier;
}

void Box::ResolveCollision(GameObject* other){

	if(other->IsID("Box"))
		{
		
		int diffX = GetX() - other->GetX();
		int diffY = GetY() - other->GetY();

		if(std::abs(diffY) > std::abs(diffX))
		{
			if(diffY > 0)
			{
				SetY(other->GetY() + (GetSizeY() + other->GetSizeY()) / 2);

				if (mVelocityY < 0)
					mVelocityY = 0;
			}
			else
			{
				SetY(other->GetY() - (GetSizeY() + other->GetSizeY()) / 2);

				if (mVelocityY > 0)
					mVelocityY = 0;

			}
		}
		else
		{
			if(diffX > 0)
			{
				SetX(other->GetX() + (GetSizeX() + other->GetSizeX()) / 2);

				if (mVelocityX < 0)
					mVelocityX = 0;
			}
			else
			{
				SetX(other->GetX() - (GetSizeX() + other->GetSizeX()) / 2);

				if (mVelocityX > 0)
					mVelocityX = 0;
			}
		}
	}
}