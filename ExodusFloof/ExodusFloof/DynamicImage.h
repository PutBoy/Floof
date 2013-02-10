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
#include <SFML\System\Vector2.hpp>

class DynamicImage
{
public:
	DynamicImage(bool rotateImage = false, sf::Vector2i center = sf::Vector2i(0,0), sf::Vector2i offset = sf::Vector2i(0, 0));

	void PushNew(std::string action, int angle);

	int GetNearestAngle(std::string action, int angle) const;
	bool IsAction(std::string action) const;

	bool RotateImage() const {return mRotateImage;};
	sf::Vector2i GetCenter() const {return mCenter;};
	sf::Vector2i GetOffset() const {return mOffset;};
private:
	bool mRotateImage;
	sf::Vector2i mCenter;
	sf::Vector2i mOffset;

	int AngleInRange(int angle) const;

	std::map<std::string, std::vector<int>> mActionAngles;
	std::set<std::string> mActions;
};

#endif