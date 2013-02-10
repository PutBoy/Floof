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
	const DynamicImage* dynImage = &dyno->GetDynamicImage(key);
	mX += dynImage->GetOffset().x;
	mY += dynImage->GetOffset().y;

	if (dynImage->IsAction(action) == false)
		mAction = "";

	if (dynImage->IsAction(mAction) == true)
	{
		mAngle = dynImage->GetNearestAngle(mAction, angle);

		ss << mAngle;
		std::string angleString = ss.str();
		ss.str("");
		std::string animKey;

		ss << key << "_" << mAction << "_" << angleString;

		if (dynImage->RotateImage())
			mAnimationJob = new AnimationJob(ss.str(), mX, mY, mFrameCount, static_cast<float>(angle - mAngle), dynImage->GetCenter());
		else
			mAnimationJob = new AnimationJob(ss.str(), mX, mY, mFrameCount, 0, dynImage->GetCenter());
	}
	else
		mAnimationJob = nullptr;
}

void DynamicImageJob::Render()
{
	if (mAnimationJob != nullptr)
		mAnimationJob->Render();
}