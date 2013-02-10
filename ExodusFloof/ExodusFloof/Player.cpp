#include "Player.h"
#include <cmath>
#include <sstream>

#include "Input.h"
#include "DynamicImageJob.h"
#include "DebugTextJob.h"
#include "Config.h"
#include "CharacterLoader.h"
#include "Collision.h"
#include "Push.h"

Player::Player(Input& input, double x, double y, int playerNumber, b2World& world):
	mPlayerNumber(playerNumber),
	mInput(input),
	GameObject(x, y, world),
	mAngleVec(0, sf::Vector2f(0,0))
{
	Config config;
	CharacterLoader* charLoader = dynamic_cast<CharacterLoader*>(config.GetLoader("Character"));
	
	jumpVelo = charLoader->getDouble("Don", "jumpVelo");
	walkSpeed = charLoader->getDouble("Don", "walkSpeed");

	acc = 0;

	gravityModifier = 1;

	mJumping = false;

	push=false;
	SetSizeX(40);
	SetSizeY(64);

	SetID("Player");

	postDeath = true;
	blink = 0;

	lives = 3;

	mAngleVec = mInput.Aim(sf::Vector2f(GetX(), GetY()));

	mAnimFrame = 0;

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

Player::~Player()
{
	GetWorld().DestroyBody(mBody);
}

void Player::Render()
{
	std::stringstream ss;
	ss << GetY() << std::endl;

	if (mAction == "walk")
		mAction = "walk";

	GetCanvas()->AddNewJob(new DynamicImageJob("bunny", GetX(), GetY(), mAnimFrame / 20, mAction, mAngleVec.angle), 1);
	GetCanvas()->AddNewJob(new DebugTextJob(ss.str(), 0, 0), 1);
}

void Player::Update()
{
	SetX(mBody->GetPosition().x);
	SetY(mBody->GetPosition().y);

	mAnimFrame++;

	mAction = "";

	mAngleVec = mInput.Aim(sf::Vector2f(GetX(), GetY()));

	if (postDeath)
	{
		blink++;

		if (blink > 2 * 60)
		{
			postDeath = false;
			blink = 0;
		}
	}

	if (mJumping)
	{
		mAction = "jump";
	}

	if (GetVelocityY() == 0)
	{
		mJumping = false;
	}

	if (gravityModifier < 0)
		SetVelocityY(GetVelocityY() - 0.05);
	else
		SetVelocityY(GetVelocityY() + 0.1);

	if(mInput.Shoot())
	{
		Fire();
	}

	//GameObject::Update();


	if (mInput.WalkLeft())
	{
		if (mAction != "jump")
			mAction = "walk";

	}
	else if (mInput.WalkRight())
	{
		SetVelocityX(walkSpeed);
		if (mAction != "jump")
		mAction = "walk";
	}
	else
	{ 
		if (mAction != "jump")
			mAction = "";

		SetVelocityX(0);
	}

	if (mInput.Jump() && !mJumping)
	{
		if ( GetVelocityY() < 0.15 && GetVelocityY() > -0.15)
		{
			SetVelocityY(-jumpVelo);
			SetY(GetY() -2.f);
			mJumping = true;
		}
	}

	std::vector<Collision::Direction> floofs;
	std::vector<Collision::Direction> boxes;

	Collision* collision = GetNextCollision();
	while (collision)
	{
		if (collision->GetGameObject()->IsID("Box"))
		{
			boxes.push_back(collision->GetDirection());
		}
		if (collision->GetGameObject()->IsID("Floof"))
		{
			floofs.push_back(collision->GetDirection());
		}

		collision = GetNextCollision();
	}

	if (!floofs.empty() && !boxes.empty())
	{
		for (size_t i = 0; i < floofs.size(); i++)
		{
			for (size_t j = 0; j < boxes.size(); j++)
			{
				if (mPlayerNumber == 0)
					mPlayerNumber = mPlayerNumber;
				//Compensate for gravity
				if(boxes[j] == Collision::DOWN && floofs[i] == Collision::UP){
					Kill();
				}
				else if(boxes[j] == Collision::UP && floofs[i] == Collision::DOWN){
					Kill();
				}
				//Irregardless of gravity
				else if(boxes[j]== Collision::LEFT && floofs[i] == Collision::RIGHT){
					Kill();
				}
				else if(boxes[j]== Collision::RIGHT && floofs[i] == Collision::LEFT){
					Kill();
				}
			}
		}
	}

	if (mInput.Push())
	{
		Drop(new Push(GetX() + mAngleVec.vec.x * 20, GetY() + mAngleVec.vec.y * 20, this));
	}

}

void Player::ReverseGravity()
{

}

void Player::Fire()
{

}

void Player::Hurt()
{

}