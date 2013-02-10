#include "Push.h"
#include "Collision.h"


Push::Push(int x, int y, GameObject* pusherObj)
	:mX(x)
	,mY(y)
	,mPusherObj(pusherObj)
	,mOriginX(pusherObj->GetX())
	,mOriginY(pusherObj->GetY())
	,GameObject(x, y, 0)
	,mFrameCount(0)
{
	SetSizeX(32);
	SetSizeY(32);
}

void Push::Update()
{
	mFrameCount++;
	double veloX = mX - mOriginX;
	double veloY = mY - mOriginY;

	Collision* collision = GetNextCollision();
	while (collision)
	{
		GameObject* obj = collision->GetGameObject();

		if (obj->IsID("Box"))
		{
			obj->SetVelocityX(obj->GetVelocityX() + veloX * 0.1);
			obj->SetVelocityY(obj->GetVelocityY() + veloY * 0.1);
			Kill();
		}

		collision = GetNextCollision();
	}

	if (mFrameCount > 5)
		Kill();
}