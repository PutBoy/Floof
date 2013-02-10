/*  Written: 2012-11-30
 *  By: Sebastian Zander
 *	
 *	Baseclass for config loaders which handles loading different tags
 */
	

#ifndef _CONFIG_LOADER_H
#define _CONFIG_LOADER_H

#include "tinyxml.h"

class ConfigLoader
{
public:
	virtual ~ConfigLoader() {};
	virtual void Load(TiXmlDocument&) = 0;

};

#endif