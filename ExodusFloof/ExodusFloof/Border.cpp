#include "Border.h"
#include "SimpleImageJob.h"

Border::Border(/*FloofContainer* floors,*/int y, bool right):GameObject(/*floors,*/32,y,1)
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