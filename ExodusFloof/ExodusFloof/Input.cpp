#include "Input.h"
#include "InputStrategy.h"
#include "AngleVec.h"
#include "SFMLWindow.h"

Input::Input(InputStrategy* inputStrategy):
	mInputStrategy(inputStrategy)
{

}

Input::Input(const Input& copy)
{
	if (&copy != this)
	{
		mInputStrategy = copy.mInputStrategy->clone();
	}
}

Input& Input::operator=(const Input& copy)
{
	if (&copy != this)
	{
		mInputStrategy = copy.mInputStrategy->clone();
	}

	return *this;
}

Input::Input(Input&& move)
{
	mInputStrategy = move.mInputStrategy;
	move.mInputStrategy = nullptr;
}

Input& Input::operator=(Input&& move)
{
	if (&move != this)
	{
		mInputStrategy = move.mInputStrategy;
		move.mInputStrategy = nullptr;
	}
	return *this;
}


bool Input::WalkLeft()const{
	return mInputStrategy->WalkLeft();
}

bool Input::WalkRight()const{
	return mInputStrategy->WalkRight();
}

AngleVec Input::Aim(sf::Vector2f position) const{
	//Adds the player's and the camera's position
	sf::View view=SFMLWindow::Acquire()->GetWindow().getView();
	return mInputStrategy->Aim(position - view.getCenter() + (view.getSize() / 2.0f));
}

bool Input::Shoot()const{
	return mInputStrategy->Shoot();
}

Input::~Input()
{
	if (mInputStrategy != nullptr)
		delete mInputStrategy;
}


bool Input::Jump() const
{
	return mInputStrategy->Jump();
}

bool Input::Push() const
{
	return mInputStrategy->Push();
}
