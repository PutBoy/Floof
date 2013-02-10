#include "Config.h"
#include "ConfigSingleton.h"

#include <cassert>

int Config::referenceCount = 0;

bool Config::invariant() const
{
	return (referenceCount >= 0);
}

Config::Config()
{
	assert(invariant());

	referenceCount++;

	mConfig = ConfigSingleton::Aquire();

	assert(invariant());
}

Config::Config(const Config&)
{
	assert(invariant());

	//in copy constructor, referenceCount MUST never be 0
	assert(referenceCount == 0);
	
	referenceCount++;

	mConfig = ConfigSingleton::Aquire();

	assert(invariant());
}

Config::~Config()
{
	referenceCount--;
	
	if (referenceCount == 0)
	{
		ConfigSingleton::Release();
	}
		
	assert(invariant());
}

ConfigLoader* Config::GetLoader(std::string key) const
{
	assert(invariant());

	return mConfig->GetLoader(key);

	assert(invariant());
}

void Config::Load(std::string file)
{
	mConfig->Load(file.c_str());
}