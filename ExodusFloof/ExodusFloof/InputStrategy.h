/*  Written: 2012-11-30 
 *  By: Oskar Nehro.
 *	Last Changed: 2012-11-30 
 *	Class to use diffrent inputs.
 */
#ifndef _INPUT_STRATEGY_H
#define _INPUT_STRATEGY_H
#include <SFML\System\Vector2.hpp>
struct AngleVec;
class InputStrategy{
public:
	virtual ~InputStrategy() {};
	virtual bool WalkLeft()const =0;
	virtual bool WalkRight()const =0;
	virtual AngleVec Aim(sf::Vector2f position) =0;
	virtual bool Shoot()const =0;
	virtual bool Jump() const = 0;
	virtual bool Push() const = 0;

	virtual InputStrategy* clone() const = 0;
protected:
	InputStrategy() {};
};
#endif