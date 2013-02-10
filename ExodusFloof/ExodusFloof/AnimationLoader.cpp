#include "AnimationLoader.h"
#include "Display.h"
#include <sstream>

void AnimationLoader::Load(TiXmlDocument& doc)
{
	TiXmlElement* root = doc.FirstChildElement("Body");
	root = root->FirstChildElement("Animation");
	while (root)
	{
		TiXmlAttribute* attribute = root->FirstAttribute();
		std::string str = attribute->Name();
		if (str == "name")
		{
			std::string animName = attribute->Value();

			TiXmlElement* element = root->FirstChildElement("a");
			
			int frames = -1;
			std::string file = "";
			while (element)
			{
				TiXmlAttribute* attrib = element->FirstAttribute();
				while (attrib)
				{
					std::string name = attrib->Name();

					if (name == "frames")
					{
						frames = attrib->IntValue();
					}
					else if (name== "file")
					{
						file = attrib->Value();
					}

					attrib = attrib->Next();
				}

				element = element->NextSiblingElement("a");
			}

			if (frames != -1 && file != "")
			{
				internalCreate(animName, file, frames);
			}
		}

		root = root->NextSiblingElement("Animation");
	}
}

void AnimationLoader::Load(std::string key, std::string file, int frames)
{
	internalCreate(key, file, frames);
}

void AnimationLoader::internalCreate(std::string key, std::string file, int frames)
{

	Display* display = Display::Acquire();
	int height = display->GetHeight(file);
	int width = display->GetWidth(file);
	int frameWidth = width / frames;

	for (int i = 0; i < frames; i++)

	{
		std::stringstream ss("");
		ss << key << i;
		display->LoadImageFromFile(file, ss.str(), frameWidth * i, 0, frameWidth * (i + 1), height);
	}

	animations.insert(animationsPair(key, Animation(frames)));
	
}

void AnimationLoader::CreateAnimation(std::string key, std::string file, int frames)
{
	internalCreate(key, file, frames);
}

const Animation& AnimationLoader::GetAnimation(std::string key)
{
	assert (animations.count(key) == 1);

	return animations[key];
}