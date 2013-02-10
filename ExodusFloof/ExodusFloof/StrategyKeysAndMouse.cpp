#include "StrategyKeysAndMouse.h"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include "SFMLWindow.h"
#include <cmath>
#include "AngleVec.h"

const double StrategyKeysAndMouse::mPi= 4*atan(1.0);

bool StrategyKeysAndMouse::WalkLeft() const{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		return true;
	else
		return false;
}
bool StrategyKeysAndMouse::WalkRight() const{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		return true;
	else
		return false;
}
bool StrategyKeysAndMouse::Shoot() const{
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		return true;
	else
		return false;
}

bool StrategyKeysAndMouse::Jump() const{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return true;
	else
		return false;
}

AngleVec StrategyKeysAndMouse::Aim(sf::Vector2f position) const{
	sf::Vector2f aim;
	sf::Vector2f shoot;

	//normalisera
	aim.x = sf::Mouse::getPosition(GetSFMLWindow()->GetWindow()).x;
	aim.y = sf::Mouse::getPosition(GetSFMLWindow()->GetWindow()).y;
	
	shoot = aim - position;

	double shootAngle = atan2(shoot.y, shoot.x);

	int degrees = (shootAngle * 180/mPi) + 90;

	return AngleVec(degrees, shoot);
}

SFMLWindow* StrategyKeysAndMouse::GetSFMLWindow() const{
	return SFMLWindow::Acquire();
}

InputStrategy* StrategyKeysAndMouse::clone() const
{
	return new StrategyKeysAndMouse(*this);
}