/*  Written: 2012-12-04
 *  By: Sebastian Zander
 *	
 *	Class for a dynamic image to be rendered
 */

#ifndef _DYNAMIC_IMAGE_JOB
#define _DYNAMIC_IMAGE_JOB

#include "Job.h"
#include "AnimationJob.h"

class DynamicImageJob: public Job
{
public:
	DynamicImageJob(std::string key, float x, float y, int frameCount, std::string action, int angle);
	virtual ~DynamicImageJob() {};

	virtual void Render();
private:
	std::string mKey;
	float mX;
	float mY;
	int mFrameCount;

	std::string mAction;
	int mAngle;

	AnimationJob* mAnimationJob;
};

#endif