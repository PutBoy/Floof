#include "ConfigSingleton.h"
#include <string>
#include <cassert>
#include "tinyxml.h"

#include "AnimationLoader.h"
#include "ImageLoader.h"
#include "DynamicImageLoader.h"
#include "CharacterLoader.h"

#include <iterator>

ConfigSingleton* ConfigSingleton::singletonInstance = nullptr;

ConfigSingleton* ConfigSingleton::Aquire()
{

	if (singletonInstance == nullptr)
		singletonInstance = new ConfigSingleton();

	return singletonInstance;
}

void ConfigSingleton::Release()
{
	assert (singletonInstance != nullptr);

	delete singletonInstance;
	
	singletonInstance = nullptr;
}

ConfigSingleton::ConfigSingleton()
{
	
	configLoaders.insert(loaderPair("Animation", new AnimationLoader()));
	configLoaders.insert(loaderPair("Image", new ImageLoader()));
	configLoaders.insert(loaderPair("DynamicImage", new DynamicImageLoader()));
	configLoaders.insert(loaderPair("Character", new CharacterLoader()));

}

void ConfigSingleton::Load(const char* file)
{
	bool fileLoaded = doc.LoadFile(file);
	assert (fileLoaded);

	internalLoadConfigs();
}

void ConfigSingleton::internalLoadConfigs()
{
	for (auto iter = configLoaders.begin();
		iter != configLoaders.end(); 
		++iter)
	{
		iter->second->Load(doc);
	}
}

ConfigLoader* ConfigSingleton::GetLoader(std::string key) const
{
	assert (configLoaders.count(key) == 1);

	return configLoaders.at(key);
}