/*  Written: 2012-12-04
 *  By: Sebastian Zander
 *	
 *	Loads <DynamicImage> tags
 */

#ifndef _DYNAMIC_IMAGE_LOADER_H
#define _DYNAMIC_IMAGE_LOADER_H

#include "ConfigLoader.h"
#include <map>
#include <string>
#include "DynamicImage.h"

class DynamicImageLoader : public ConfigLoader
{
public:
	virtual void Load(TiXmlDocument&);
	void Load(std::string key, std::string file, int frames);

	const DynamicImage& GetDynamicImage(std::string key);

private:
	void internalCreate(std::string key, std::string file, 
			int frames, std::string action, int angle);
	
	typedef std::pair<std::string, DynamicImage> dynamicImagePair;
	std::map<std::string, DynamicImage> dynamicImages;
};

#endif