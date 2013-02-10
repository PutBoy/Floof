/*  Written: 2012-11-30
 *  By: Oskar Nehro.
 *	Last Changed: 2012-11-30 
 *	Class to get inputs.
 */
#ifndef _INPUT_H
#define _INPUT_H
#include <SFML\System\Vector2.hpp>

class InputStrategy;
struct AngleVec;

class Input{
public:
	Input(InputStrategy*);
	
	Input(const Input&);
	Input& operator=(const Input&);

	Input(Input&&);
	Input& operator=(Input&&);

	~Input();
	bool WalkLeft()const;
	bool WalkRight()const;
	AngleVec Aim(sf::Vector2f position) const;
	bool Shoot()const;
	bool Jump() const;
private:
	InputStrategy* mInputStrategy;
};
#endif