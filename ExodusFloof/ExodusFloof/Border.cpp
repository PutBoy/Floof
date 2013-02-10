#include "Border.h"
#include "SimpleImageJob.h"

Border::Border(int y, bool right, b2World& world):GameObject(32,y, world)
{
	display=Display::Acquire();
	mRight=right;
	SetID("Border");
	SetSizeX(64);
	SetSizeY(64);

	if (mRight)
	{
		SetX(800-32);
	}
}

void Border::Render()
{
	if (mRight)
		GetCanvas()->AddNewJob(new SimpleImageJob("BorderRight", GetX() - 32, GetY() - 32), 2);
	else
		GetCanvas()->AddNewJob(new SimpleImageJob("BorderLeft", GetX() - 32, GetY() - 32), 2);
}

void Border::Update()
{
	const int moveSpeed=1;

	SetX(GetX()+moveSpeed);
}