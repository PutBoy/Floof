/*  Written: 2012-11-30
 *  By: Oskar Nehro.
 *	Last Changed: 2012-11-30
 *	Class to use keys as input.
 */
#ifndef _STRATEGY_KEYS_H
#define _STRATEGY_KEYS_H
#include "InputStrategy.h"

class StrategyKeys: public InputStrategy{
public:
	StrategyKeys(){};
	
	virtual bool WalkLeft() const;
	virtual bool WalkRight() const;
	virtual AngleVec Aim(sf::Vector2f position) const;
	virtual bool Shoot() const;
	virtual bool Jump() const;

	virtual InputStrategy* clone() const;
private:

};
#endif