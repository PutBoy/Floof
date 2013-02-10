/*  Written: 2012-11-30
 *  By: Sebastian Zander
 *	
 *	Class for an animation to be rendered
 */

#ifndef _ANIMATION_JOB_H
#define _ANIMATION_JOB_H

#include "Job.h"
#include <SFML\System\Vector2.hpp>

class AnimationJob: public Job
{
public:
	AnimationJob(std::string key, float x, float y, int frameCount, float angle = 0, sf::Vector2i center = sf::Vector2i(0,0));
	virtual ~AnimationJob() {};

	virtual void Render();
private:
	sf::Vector2i mCenter;
	float mAngle;

	std::string mKey;
	float mX;
	float mY;
	int mFrameCount;
};

#endif