/*  Written: 2012-11-30
 *  By: Oskar Nehro.
 *	Last Changed: 2012-12-04
 *	Class to use keys as input.
 */
#ifndef _STRATEGY_KEYS_AND_MOUSE_H
#define _STRATEGY_KEYS_AND_MOUSE_H
#include "InputStrategy.h"
class SFMLWindow;

class StrategyKeysAndMouse: public InputStrategy{
public:
	StrategyKeysAndMouse(){};
	virtual bool WalkLeft() const;
	virtual bool WalkRight() const;
	virtual AngleVec Aim(sf::Vector2f position) const;
	virtual bool Shoot() const;
	virtual bool Jump() const;

	virtual InputStrategy* clone() const;
private:
	SFMLWindow* GetSFMLWindow() const;

    static double const mPi;
};
#endif