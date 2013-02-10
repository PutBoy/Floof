#include "StrategyKeys.h"
#include <SFML\Window\Keyboard.hpp>
#include "AngleVec.h"

bool StrategyKeys::WalkLeft() const{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return true;
	else
		return false;
}
bool StrategyKeys::WalkRight() const{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return true;
	else
		return false;
}
bool StrategyKeys::Shoot() const{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return true;
	else
		return false;
}
bool StrategyKeys::Jump() const{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		return true;
	else
		return false;

}

AngleVec StrategyKeys::Aim(sf::Vector2f position) const{
	
	sf::Vector2f aim;
	int degrees; 

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		aim.x = -1;
		aim.y = 0;
		degrees=180;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
		aim.x = 1;
		aim.y = 0;
		degrees=0;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		aim.x = -1;
		aim.y = -1;		
		degrees=135;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		aim.x = 1;
		aim.y = -1;	
		degrees=45;
	}

	return AngleVec(degrees,aim);
}

InputStrategy* StrategyKeys::clone() const
{
	return new StrategyKeys(*this);
}