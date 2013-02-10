#include "ColliderComponent.h"
#include "GameObject.h"

ColliderComponent::ColliderComponent(GameObject* object)
	:mObject(object)
	,mX(object->GetX())
	,mY(object->GetY())
	,mSizeX(object->GetSizeX())
	,mSizeY(object->GetSizeY())
	,mWeight(object->GetWeight())
{}