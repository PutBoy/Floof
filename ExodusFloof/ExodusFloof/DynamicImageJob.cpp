#include "Config.h"
#include "DynamicImageLoader.h"
#include <sstream>
#include "DynamicImageJob.h"

#include <cassert>

DynamicImageJob::DynamicImageJob
	(std::string key, float x, float y, 
	int frameCount, std::string action, int angle):
	mKey(key),
	mX(x),
	mY(y),
	mFrameCount(frameCount),
	mAction(action),
	mAngle(angle)
{
	std::stringstream ss;
	Config cfg;
	DynamicImageLoader* dyno = dynamic_cast<DynamicImageLoader*>(cfg.GetLoader("DynamicImage"));
	assert (dyno != 0);
		
	if (dyno->GetDynamicImage(key).IsAction(action) == false)
		mAction = "";

	if (dyno->GetDynamicImage(key).IsAction(mAction) == true)
	{
		mAngle = dyno->GetDynamicImage(key).GetNearestAngle(mAction, angle);

		ss << mAngle;
		std::string angleString = ss.str();
		ss.str("");
		std::string animKey;

		ss << key << "_" << mAction << "_" << angleString;

		mAnimationJob = new AnimationJob(ss.str(), mX, mY, mFrameCount);
	}
	else
		mAnimationJob = nullptr;
}

void DynamicImageJob::Render()
{
	if (mAnimationJob != nullptr)
		mAnimationJob->Render();
}