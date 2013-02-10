#ifndef _ANGLE_VEC_H
#define _ANGLE_VEC_H

struct AngleVec{
	AngleVec(double myAngle, sf::Vector2f myVec) : angle(myAngle), vec(myVec) {};
	
	double angle;
	sf::Vector2f vec;
};

#endif