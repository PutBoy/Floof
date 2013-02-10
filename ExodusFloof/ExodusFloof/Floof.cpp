#include "Floof.h"
#include "StaticObject.h"
#include "Collidable.h"
#include "SimpleImageJob.h"

Floof::Floof(int x, int y):
	GameObject(x, y, 1)
{
	SetSizeX(64);
	SetSizeY(64);

	SetID("Floof");
}

void Floof::Render()
{
	GetCanvas()->AddNewJob(new SimpleImageJob("Floof", GetX() - 32, GetY() - 32), 1);
}
