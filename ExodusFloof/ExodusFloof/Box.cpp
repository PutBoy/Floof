#include "Box.h"
#include <cmath>
#include "SimpleImageJob.h"

Box::Box(double x, double y, int gravity, b2World& world):
	GameObject(x, y, world),
	gravityModifier(gravity)
{

	SetSizeY(62);
	SetSizeX(62);
	SetID("Box");

	b2BodyDef bodyDef;
	bodyDef.position.Set(x, y);
	bodyDef.type = b2_dynamicBody;
	mBody = world.CreateBody(&bodyDef);

	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(32.0f, 32.0f);

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

	SetX(mBody->GetPosition().x);
	SetY(mBody->GetPosition().y);
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
	*/
	//GameObject::Update();
}

void Box::ReverseGravity(){
	gravityModifier = -gravityModifier;
}
