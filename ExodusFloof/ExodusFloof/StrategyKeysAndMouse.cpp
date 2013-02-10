#include "StrategyKeysAndMouse.h"
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include "SFMLWindow.h"
#include <cmath>
#include "AngleVec.h"

const double StrategyKeysAndMouse::mPi= 4*atan(1.0);

bool StrategyKeysAndMouse::WalkLeft() const{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
}
bool StrategyKeysAndMouse::WalkRight() const{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}
bool StrategyKeysAndMouse::Shoot() const{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

bool StrategyKeysAndMouse::Jump() const{
	
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
}

bool StrategyKeysAndMouse::Push() const
{
	return sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
}

AngleVec StrategyKeysAndMouse::Aim(sf::Vector2f position){
	sf::Vector2f aim;
	sf::Vector2f shoot;

	//normalisera
	aim.x = sf::Mouse::getPosition(GetSFMLWindow()->GetWindow()).x;
	aim.y = sf::Mouse::getPosition(GetSFMLWindow()->GetWindow()).y;
	
	shoot = aim - position;
	shoot = shoot * (1 / std::sqrt(shoot.x * shoot.x + shoot.y * shoot.y));

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