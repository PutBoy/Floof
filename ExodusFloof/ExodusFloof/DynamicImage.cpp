#include "DynamicImage.h"
#include <algorithm>
#include <cassert>

DynamicImage::DynamicImage(bool rotateImage, sf::Vector2i center, sf::Vector2i offset)
	:mRotateImage(rotateImage)
	,mCenter(center)
	,mOffset(offset)
{

}

int DynamicImage::AngleInRange(int angle) const
{
	angle = angle % 360;

	if (angle < 0)
	{
		angle = 360 + angle ;
	}

	return angle;
}

int DynamicImage::GetNearestAngle(std::string action, int angle) const
{
	assert(mActionAngles.count(action) == 1);

	angle = AngleInRange(angle);
	int firstAngle;
	int secondAngle;
	bool foundAngle = false;
	
	std::vector<int> angles = mActionAngles.at(action);

	if (angles.size() == 1)
	{
		return angles.back();
	}

	int i = angles.size();
	for (i = 0; i < angles.size() ; ++i)
	{
		if (angle < angles[i])
		{
			foundAngle = true;
			firstAngle = angles[i];
			break;
		}
	}

	int middle;

	if (!foundAngle)
	{
		firstAngle = angles[0];
		secondAngle = angles.back();
		//This might not be right, time will tell.
		middle = (secondAngle + firstAngle) / 2 - 180;
		if (angle > firstAngle)
			angle = angle - 360;
	}
	else
	{
		if (i == 0)
		{
			secondAngle = angles.back();
			//This might not be right, time will tell.
			middle = (secondAngle + firstAngle) / 2 - 180;
			if (angle > firstAngle)
				angle = angle - 360;
		}
		else
		{
			secondAngle = angles[i - 1];
			middle = (secondAngle + firstAngle) / 2;
		}
	}
	
	if (angle < middle)
		return AngleInRange(secondAngle);
	else
		return AngleInRange(firstAngle);
}

bool DynamicImage::IsAction(std::string action) const
{
	return mActions.count(action) == 1;
}

void DynamicImage::PushNew(std::string action, int angle)
{
	mActions.insert(action);

	if (mActionAngles.count(action) == 0)
	{
		mActionAngles.insert(std::pair<std::string, std::vector<int>>(action, std::vector<int>()));
	}

	mActionAngles[action].push_back(angle);
	std::sort(mActionAngles[action].begin(), mActionAngles[action].end());
}