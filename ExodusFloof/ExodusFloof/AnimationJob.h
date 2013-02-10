/*  Written: 2012-11-30
 *  By: Sebastian Zander
 *	
 *	Class for an animation to be rendered
 */

#ifndef _ANIMATION_JOB_H
#define _ANIMATION_JOB_H

#include "Job.h"

class AnimationJob: public Job
{
public:
	AnimationJob(std::string key, float x, float y, int frameCount);
	virtual ~AnimationJob() {};

	virtual void Render();
private:
	std::string mKey;
	float mX;
	float mY;
	int mFrameCount;
};

#endif