/*  Written: 2012-12-04
 *  By: Sebastian Zander
 *	
 *	Class to wrap the ConfigSingleton
 */

#ifndef _CONFIG_H
#define _CONFIG_H

#include <string>

class ConfigLoader;
class ConfigSingleton;

class Config
{
public:
	Config();
	Config(const Config&);
	~Config();

	void Load(std::string file);

	ConfigLoader* GetLoader(std::string key) const;
private:
	bool invariant() const;

	ConfigSingleton* mConfig;
	static int referenceCount;
};


#endif