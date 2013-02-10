#include "StaticObject.h"

StaticObject::StaticObject(GameObject* object) : ColliderComponent(object)
{

}

//�ndrat
void StaticObject::SetOtherX(double x, ColliderComponent* other)
{
	other->SetX(x);
}

void StaticObject::SetOtherY(double y, ColliderComponent* other)
{
	other->SetY(y);
}