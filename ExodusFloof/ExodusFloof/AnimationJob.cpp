#include "AnimationJob.h"
#include "Config.h"
#include "AnimationLoader.h"
#include <sstream>

#include <cassert>

AnimationJob::AnimationJob
	(std::string key, float x, float y, int frameCount):
	mKey(key),
	mX(x),
	mY(y),
	mFrameCount(frameCount)
{
	Config cfg;
	AnimationLoader* anim = dynamic_cast<AnimationLoader*>(cfg.GetLoader("Animation"));
	assert (anim != 0);

	int maxFrames = anim->GetAnimation(key).GetFrames();

	mFrameCount = mFrameCount % maxFrames;

	if (mFrameCount < 0)
	{
		mFrameCount = maxFrames + mFrameCount ;
	}
		

	std::stringstream ss;
	ss << key << mFrameCount;
	mKey = ss.str();

}

void AnimationJob::Render()
{
	GetDisplay()->DrawImage(mKey, mX, mY);
}