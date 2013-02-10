#include "Bullet.h"
#include "SimpleImageJob.h"

Bullet::Bullet(int x, int y, double speed, sf::Vector2f targetDirection)
	:GameObject(x, y, 0)
{
	SetID("Bullet");
	SetSizeX(10);
	SetSizeY(10);

	double directionLength=std::sqrt(targetDirection.x*targetDirection.x+targetDirection.y*targetDirection.y);
	double scalar=speed/directionLength;
	SetVelocityX(scalar*targetDirection.x);
	SetVelocityY(scalar*targetDirection.y);
}

void Bullet::Update()
{
	SetX(GetX()+GetVelocityX());
	SetY(GetY()+GetVelocityY());
}

void Bullet::Render()
{
	GetCanvas()->AddNewJob(new SimpleImageJob("Bullet", GetX()-32, GetY()-32), 1);
}