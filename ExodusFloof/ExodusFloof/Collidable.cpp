#include "Collidable.h"
#include "GameObject.h"

Collidable::Collidable(GameObject* object):ColliderComponent(object)
{

}

void Collidable::SetX(double x)
{
	GetObject()->SetX(x);
	GetObject()->SetVelocityX(0);
}

void Collidable::SetY(double y)
{
	GetObject()->SetY(y);
	GetObject()->SetVelocityY(0);
}

void Collidable::SetOtherX(double x, ColliderComponent* other)
{
	other->SetX(x);
}

void Collidable::SetOtherY(double y, ColliderComponent* other)
{
	other->SetY(y);
}