#include "CollisionHandler.h"
#include "ColliderComponent.h"
#include "GameObject.h"
#include "Collision.h"

void CollisionHandler::Push(ColliderComponent* component)
{
	mComponents.push_back(component);
}

void CollisionHandler::Clear()
{
	for (size_t i = 0; i < mComponents.size(); i++)
	{
		delete mComponents[i];
	}

	mComponents.clear();
}

void CollisionHandler::Collide()
{
	for (int i=0; i<mComponents.size(); i++)
	{
		for (int j=i+1; j<mComponents.size(); j++)
		{
			if (TestCollision(mComponents[i], mComponents[j]))
			{
				HandleCollision(mComponents[i], mComponents[j]);
				HandleCollision(mComponents[j], mComponents[i]);
			}
		}
	}
}

#include "StaticObject.h"

void CollisionHandler::HandleCollision(ColliderComponent* c0, ColliderComponent* c1)
{
	int distanceY = (c0->GetSizeY() / 2) + (c1->GetSizeY() / 2);
	int distanceX = (c0->GetSizeX() / 2) + (c1->GetSizeX() / 2);
		
	double diffX = (c0->GetX() - c1->GetX()) / distanceX;
	double diffY = (c0->GetY() - c1->GetY()) / (distanceY - 1);

	double ratio;

	if (dynamic_cast<StaticObject*>(c0) || dynamic_cast<StaticObject*>(c1))
	{
		ratio = 1.0;
	}
	else
	{
		ratio = 1.0;
	}
	

	if (abs(diffX) < abs(diffY))
	{
		if(diffY > 0)
		{
			c0->SetOtherY(c0->GetY() - distanceY * ratio, c1);

			c0->GetObject()->PushCollision(new Collision(c1->GetObject(), Collision::DOWN));
		}
		else
		{
			c0->SetOtherY(c0->GetY() + distanceY * ratio, c1);

			c0->GetObject()->PushCollision(new Collision(c1->GetObject(), Collision::UP));
		}
	}
	else
	{
		if(diffX > 0)
		{
			c0->GetObject()->PushCollision(new Collision(c1->GetObject(), Collision::RIGHT));

			c0->SetOtherX(c0->GetX() - distanceX * ratio - 1, c1);
		}
		else
		{
			c0->GetObject()->PushCollision(new Collision(c1->GetObject(), Collision::LEFT));

			c0->SetOtherX(c0->GetX() + distanceX * ratio + 1, c1);
		}
	}
}

bool CollisionHandler::TestCollision(ColliderComponent* c0, ColliderComponent* c1)
{
	bool isCollided = false;

	if ((c0->GetSizeX() == -1 && c0->GetSizeY() == -1) || (c1->GetSizeX() == -1 && c1->GetSizeY() == -1))
	{
		isCollided = false;
	}
	else 
	{
		int top1 = c0->GetY() - c0->GetSizeY() / 2;
		int top2 = c1->GetY() - c1->GetSizeY() / 2;

		int bottom1 = c0->GetY() + c0->GetSizeY() / 2;
		int bottom2 = c1->GetY() + c1->GetSizeY() / 2;

		int left1 = c0->GetX() - c0->GetSizeX() / 2;
		int left2 = c1->GetX() - c1->GetSizeX() / 2;

		int right1 = c0->GetX() + c0->GetSizeX() / 2;
		int right2 = c1->GetX() + c1->GetSizeX() / 2;

		if (bottom1 < top2) return false;        
		if (top1 > bottom2) return false;        
		if (right1 < left2) return false;        
		if (left1 > right2) return false;

		return true;
	
	}

    return (isCollided);
}