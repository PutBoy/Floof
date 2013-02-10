/*  Written: 2012-11-30
 *  By: Sebastian Zander
 *	
 *	Loads <animation> tags
 */

#ifndef _ANIMATION_LOADER_H
#define _ANIMATION_LOADER_H

#include "ConfigLoader.h"
#include <map>
#include <string>
#include "Animation.h"

class AnimationLoader : public ConfigLoader
{
public:
	virtual void Load(TiXmlDocument&);
	void Load(std::string key, std::string file, int frames);

	const Animation& GetAnimation(std::string key);

	void CreateAnimation(std::string key, std::string file, int frames);

private:
	void internalCreate(std::string key, std::string file, int frames);
	
	typedef std::pair<std::string, Animation> animationsPair;
	std::map<std::string, Animation> animations;
};
#endif