#include "Box.h"
#include <cmath>
#include "SimpleImageJob.h"
#include "Collision.h"

Box::Box(double x, double y, int gravity, b2World& world):
	GameObject(x, y, world),
	gravityModifier(gravity)
{

	SetSizeY(62);
	SetSizeX(62);
	SetID("Box");

	b2BodyDef bodyDef;
	bodyDef.position.Set(x / 32.f, y / 32.f);
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	mBody = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(1.0f, 1.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	mBody->CreateFixture(&fixtureDef);
}

Box::~Box()
{
	GetWorld().DestroyBody(mBody);
}

void Box::Render()
{
	GetCanvas()->AddNewJob(new SimpleImageJob("Box", GetX() - 32, GetY() - 32), 0);
}

void Box::Update(){

	SetX(mBody->GetPosition().x * 32);
	SetY(mBody->GetPosition().y * 32);
	/*
	SetVelocityY(GetVelocityY() + 0.1 * static_cast<double>(gravityModifier));

	if (GetVelocityX() < 0)
	{
		SetVelocityX(GetVelocityX() + 0.5);
		if (GetVelocityX() > 0)
			SetVelocityX(0);
	}
	else if (GetVelocityX() > 0)
	{
		SetVelocityX(GetVelocityX() - 0.5);
		if (GetVelocityX() < 0)
			SetVelocityX(0);
	}

	GameObject::Update();

	*/
	//GameObject::Update();
	Collision* collision = GetNextCollision();
	while (collision)
	{
		if (collision->GetGameObject()->IsID("Bullet"))
		{
			collision->GetGameObject()->Kill();
			ReverseGravity();
		}
		collision = GetNextCollision();
	}
}

void Box::ReverseGravity(){
	gravityModifier = -gravityModifier;
}
