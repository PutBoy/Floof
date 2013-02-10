#include "DynamicImageLoader.h"
#include "Display.h"
#include <sstream>
#include <cassert>
#include "Config.h"
#include "AnimationLoader.h"

void DynamicImageLoader::Load(TiXmlDocument& doc)
{
	TiXmlElement* root = doc.FirstChildElement("Body");
	root = root->FirstChildElement("DynamicImage");
	while (root)
	{
		TiXmlAttribute* attribute = root->FirstAttribute();
		std::string str = attribute->Name();
		if (str == "name")
		{
			std::string dynamicImageName = attribute->Value();


			    //<a rotateimage ="true"/>
				//<a centerx ="32" centery="32"/>

			TiXmlElement* element = root->FirstChildElement("a");
			
			bool rotateimage = false;
			int centerx = 0;
			int centery = 0;
			int offsetx = 0;
			int offsety = 0;

			while (element)
			{
				TiXmlAttribute* attrib = element->FirstAttribute();
				while (attrib)
				{
					std::string name = attrib->Name();
					std::string value = attrib->Value();

					if (name == "rotateimage")
					{
						if (value == "true" || value == "True")
							rotateimage = true;
						else
							rotateimage = false;
					}
					else if (name== "centerx")
					{
						centerx = attrib->IntValue();
					}
					else if (name== "centery")
					{
						centery = attrib->IntValue();
					}
					else if (name== "offsetx")
					{
						offsetx = attrib->IntValue();
					}
					else if (name== "offsety")
					{
						offsety = attrib->IntValue();
					}

					attrib = attrib->Next();
				}

				element = element->NextSiblingElement("a");
			}
				
			if (dynamicImages.count(dynamicImageName) == 0)
				dynamicImages.insert(dynamicImagePair(dynamicImageName, DynamicImage(rotateimage, sf::Vector2i(centerx, centery), sf::Vector2i(offsetx, offsety))));
	

			
			TiXmlElement* animation = root->FirstChildElement("Animation");


			int frames = -1;
			std::string file = "";
			int angle = 0;
			std::string action = "";

			while (animation)
			{
				
				TiXmlElement* animElement = animation->FirstChildElement("a");
				while (animElement)
				{
					TiXmlAttribute* attrib = animElement->FirstAttribute();
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
						else if (name == "action")
						{
							action = attrib->Value();
						}
						else if (name== "angle")
						{
							angle = attrib->IntValue();
						}

						attrib = attrib->Next();
					}

					animElement = animElement->NextSiblingElement("a");
				}

				internalCreate(dynamicImageName, file, frames, action, angle);

				animation = animation->NextSiblingElement();

			}

			if (file == "" || frames <= 0)
				continue;
			else
			{
				TiXmlElement* element = root->FirstChildElement("a");
			
				while (element)
				{
					TiXmlAttribute* attrib = element->FirstAttribute();
					while (attrib)
					{
						std::string name = attrib->Name();

						if (name == "action")
						{
							action = attrib->Value();
						}
						else if (name== "angle")
						{
							angle = attrib->IntValue();
						}

						attrib = attrib->Next();
					}

					element = element->NextSiblingElement("a");
				}
				
				internalCreate(dynamicImageName, file, frames, action, angle);

			}
			
		}

		root = root->NextSiblingElement("DynamicImage");
	}
}

void DynamicImageLoader::internalCreate(std::string key, std::string file, 
			int frames, std::string action, int angle)
{
	std::stringstream ss;
	
	if (dynamicImages.count(key) == 0)
		dynamicImages.insert(dynamicImagePair(key, DynamicImage()));
	
	dynamicImages[key].PushNew(action, angle);
	Config cfg;

	AnimationLoader* animLoader = dynamic_cast<AnimationLoader*>(cfg.GetLoader("Animation"));

	std::string animationKey;
	
	ss << angle;
	std::string angleString = ss.str();

	ss.str("");

	ss << key << "_" << action << "_" << angleString;

	animationKey = ss.str();

	animLoader->CreateAnimation(animationKey, file, frames);
}


const DynamicImage& DynamicImageLoader::GetDynamicImage(std::string key)
{
	return dynamicImages.at(key);
}