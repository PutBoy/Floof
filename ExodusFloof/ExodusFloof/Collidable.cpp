#include "Collidable.h"
#include "GameObject.h"

Collidable::Collidable(GameObject* object):ColliderComponent(object)
{

}

void Collidable::SetX(double x)
{
	if (GetObject()->GetX() < x && GetObject()->GetVelocityX() > 0)
		GetObject()->SetVelocityX(0);
	else if (GetObject()->GetX() > x && GetObject()->GetVelocityX() < 0)
		GetObject()->SetVelocityX(0);

	GetObject()->SetX(x);
	
}

void Collidable::SetY(double y)
{
	if (GetObject()->GetY() > y && GetObject()->GetVelocityY() > 0)
		GetObject()->SetVelocityY(0);
	else if (GetObject()->GetY() < y && GetObject()->GetVelocityY() < 0)
		GetObject()->SetVelocityY(0);

	GetObject()->SetY(y);
}

void Collidable::SetOtherX(double x, ColliderComponent* other)
{
	other->SetX(x);
}

void Collidable::SetOtherY(double y, ColliderComponent* other)
{
	other->SetY(y);
}