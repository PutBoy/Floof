/*  Written: 2012-12-04
 *  By: Sebastian Zander
 *	
 *	Class to store info for a config-loaded DynamicImage.
 */

#ifndef _DYNAMIC_IMAGE
#define _DYNAMIC_IMAGE

#include <set>
#include <vector>
#include <string>
#include <map>

class DynamicImage
{
public:
	DynamicImage();

	void PushNew(std::string action, int angle);

	int GetNearestAngle(std::string action, int angle) const;
	bool IsAction(std::string action) const;

private:
	int AngleInRange(int angle) const;

	std::map<std::string, std::vector<int>> mActionAngles;
	std::set<std::string> mActions;
};

#endif