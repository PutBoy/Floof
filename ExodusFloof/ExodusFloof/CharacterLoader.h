/*  Written: 2013-01-13
 *  By: Sebastian Zander
 *	
 *	Loads and stores <character> tags
 */

#ifndef _CHARACTER_LOADER_H
#define _CHARACTER_LOADER_H

#include "ConfigLoader.h"

#include <map>
#include <string>

class CharacterLoader : public ConfigLoader
{
public:
	virtual void Load(TiXmlDocument&);

	std::string getString(const std::string& character, const std::string& tag) const;
	int getInt(const std::string& character, const std::string& tag) const;
	double getDouble(const std::string character, const std::string& tag) const;

	bool isLoaded(const std::string& character, const std::string& tag) const;
private:
	void addValue(const std::string& character, const std::string& tag, const std::string& value);

	std::map<std::string, std::string> valueMap;

};

#endif