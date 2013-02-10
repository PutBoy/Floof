#include "Player.h"
#include <cmath>
#include <sstream>

#include "Input.h"
#include "DynamicImageJob.h"
#include "DebugTextJob.h"

Player::Player(Input& input, int x, int y, int playerNumber):
	mPlayerNumber(playerNumber),
	mInput(input),
	GameObject(x, y),
	mAngleVec(0, sf::Vector2f(0,0))
{
	acc = 0;

	gravityModifier = 1;

	mJumping = false;
	mFalling = false;

	push=false;
	SetSizeX(46);
	SetSizeY(64);

	SetID("Player");

	postDeath = true;
	blink = 0;

	lives = 3;

	mAngleVec = mInput.Aim(sf::Vector2f(GetX(), GetY()));
}

void Player::Render()
{
	std::stringstream ss;
	ss << mAngleVec.angle << std::endl;
	ss << mAngleVec.vec.x << std::endl;
	ss << mAngleVec.vec.y << std::endl;
	GetCanvas()->AddNewJob(new DynamicImageJob("bunny", GetX() - 32, GetY() - 32, 0, mAction, mAngleVec.angle), 0);
	GetCanvas()->AddNewJob(new DebugTextJob(ss.str(), 0, 0), 1);
}

void Player::Update()
{
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

		if (gravityModifier < 0 && mVelocityY < 0)
		{
			mFalling = true;
		}
		else if(gravityModifier > 0 && mVelocityY > 0)
		{
			mFalling = true;
		}
	}

	if (GetY() >= 500)
	{
		mVelocityY = 0;
		SetY(500);
	}

	if (mFalling && mVelocityY == 0)
	{
		mJumping = false;
		mFalling = false;
	}

	if (gravityModifier < 0)
		mVelocityY -= 0.05;
	else
		mVelocityY += 0.1;

	if(mInput.Shoot())
	{
		Fire();
	}

	GameObject::Update();


	if (mInput.WalkLeft())
	{
		mVelocityX = -1;
	}
	else if (mInput.WalkRight())
	{
		mVelocityX = 1;
	}
	else
	{ 
		mVelocityX = 0;
	}

	if (mInput.Jump() && !mJumping)
	{
		mVelocityY = -2;
		SetY(GetY() -2);
		mJumping = true;
	}

}

void Player::ReverseGravity()
{

}

void Player::ResolveCollision(GameObject* other)
{
	if(other->IsID("Box"))
	{
		boxCollided = true;

		int diffX = GetX() - other->GetX();
		int diffY = GetY() - other->GetY();

		if(std::abs(diffY) > std::abs(diffX))
		{
			if(diffY > 0)
			{
				SetY(other->GetY() + (GetSizeY() + other->GetSizeY()) / 2);

				if (mVelocityY < 0)
					mVelocityY = 0;
			}
			else
			{
				SetY(other->GetY() - (GetSizeY() + other->GetSizeY()) / 2);

				if (mVelocityY > 0)
					mVelocityY = 0;
			}

		}
		else
		{
			if(diffX > 0)
			{
				SetX(other->GetX() + (GetSizeX() + other->GetSizeX()) / 2 + 2);

				if (mVelocityX < 0)
					mVelocityX = 0;
			}
			else
			{
				SetX(other->GetX() - (GetSizeX() + other->GetSizeX()) / 2 - 2);

				if (mVelocityX > 0)
					mVelocityX = 0;
			}
		}
	}

}

void Player::Fire()
{

}

void Player::Hurt()
{

}