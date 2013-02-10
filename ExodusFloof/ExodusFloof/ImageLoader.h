/*  Written: 2012-11-30
 *  By: Sebastian Zander
 *	
 *	Loads image tags.
 */

#ifndef _IMAGE_LOADER_H
#define _IMAGE_LOADER_H

#include "ConfigLoader.h"
#include "Image.h"

#include <map>
#include <string>

class ImageLoader : public ConfigLoader
{
public:
	virtual void Load(TiXmlDocument&);

private:
	void internalCreate(std::string key, std::string fileName, int x1, int x2, int y1, int y2);

	std::map<std::string, Image> images;
};

#endif