#include "Player.h"
#include <cmath>
#include <sstream>
#include <iostream>

#include "Input.h"
#include "DynamicImageJob.h"
#include "DebugTextJob.h"
#include "Config.h"
#include "CharacterLoader.h"
#include "Collision.h"
#include "Push.h"

Player::Player(Input& input, double x, double y, int playerNumber, b2World& world):
	GameObject(x, y, world),
	mPlayerNumber(playerNumber),
	mInput(input),
	mAngleVec(0, sf::Vector2f(0,0)),
	mFirstShot(true)
	
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

Player::~Player()
{
	GetWorld().DestroyBody(mBody);
}

void Player::Render()
{

	if (mAction == "walk")
		mAction = "walk";


	GetCanvas()->AddNewJob(new DynamicImageJob("bunny", GetX()-32.f, GetY()-32.f, mAnimFrame / 20, mAction, mAngleVec.angle), 1);

}

void Player::Update()
{

	SetX(mBody->GetPosition().x * 32.f);
	SetY(mBody->GetPosition().y * 32.f);

	const double GRAV_SHOT_WAIT=1.0;


//	std::cout <<"spriteX: "<< GetY()<<" "<<"bodyX: "<< mBody->GetPosition().y<<std::endl;


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


	//Shoot grav gun
	if(mInput.Shoot() && (mFirstShot || mLastGravShot.getElapsedTime().asSeconds()>GRAV_SHOT_WAIT))

	{
		mFirstShot=false;
		mLastGravShot.restart();
		Fire();
	}
		
	if (mInput.Jump() && !mJumping)
	{
		if ( GetVelocityY() < 0.15 && GetVelocityY() > -0.15)
		{
			//SetVelocityY(-jumpVelo);
			//SetY(GetY() -2.f);
			mBody->ApplyLinearImpulse(b2Vec2(0,-2.f),mBody->GetWorldCenter());
			mJumping = true;
		}
		
	}
	b2Vec2 velocity = mBody->GetLinearVelocity();

	if (mInput.WalkLeft())
	{
		if (mAction != "jump"){
			
			velocity.x = -0.5*mBody->GetMass();
			mAction = "walk";
		}
	}
	else if (mInput.WalkRight())
	{
		velocity.x = 0.5*mBody->GetMass();
		if (mAction != "jump")
		mAction = "walk";
	}
	else
	{ 
		if (mAction != "jump")
			mAction = "";
	}


	mBody->SetLinearVelocity(velocity);

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
		if (collision->GetGameObject()->IsID("Bullet") && mLastGravShot.getElapsedTime().asSeconds()>1.0)
		{
			collision->GetGameObject()->Kill();
			ReverseGravity();
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
	gravityModifier*=-1;
}

void Player::Fire()
{
	const double GRAV_SHOT_SPEED=5.0;
	Drop(new Bullet(GetX(), GetY(), GRAV_SHOT_SPEED, mAngleVec.vec, GetWorld()));
}

void Player::Hurt()
{

}