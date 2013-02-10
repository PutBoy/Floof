/*  Written: 2012-11-30
 *  By: Sebastian Zander
 *	
 *	Singleton for loading and storing a config.
 */

#ifndef _CONFIG_SINGLETON_H
#define _CONFIG_SINGLETON_H

#include <string>
#include "tinyxml.h"
#include <map>
#include <string>
#include "ConfigLoader.h"

class ConfigSingleton
{
public:
		static ConfigSingleton* Aquire();
	static void Release();

	void Load(const char*);

	ConfigLoader* GetLoader(std::string key) const;
private:
	ConfigSingleton();
	ConfigSingleton(const ConfigSingleton&);
	const ConfigSingleton& operator=(const ConfigSingleton&);
	
	void internalLoadConfigs();

	ConfigSingleton(const char*);

	TiXmlDocument doc;

	static ConfigSingleton* singletonInstance;
	
	typedef std::pair<std::string, ConfigLoader*> loaderPair;
	std::map<std::string, ConfigLoader*> configLoaders;
};

#endif