#include "ImageLoader.h"
#include "Display.h"

void ImageLoader::Load(TiXmlDocument& doc)
{
	TiXmlElement* root = doc.FirstChildElement("Body");
	root = root->FirstChildElement("Image");
	while (root)
	{
		TiXmlAttribute* attribute = root->FirstAttribute();
		std::string str = attribute->Name();
		if (str == "name")
		{
			std::string imageName = attribute->Value();
			std::string fileName;
			int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
			TiXmlElement* element = root->FirstChildElement("a");
			if (element)
			{
				if (element->Attribute("file"))
				{
					fileName = element->Attribute("file");
				}
			}

			element = root->FirstChildElement("rect");

			while (element)
			{

				TiXmlAttribute* attrib = element->FirstAttribute();
				while (attrib)
				{
					std::string name = attrib->Name();
					if (name == "x1")
					{
						x1 = attrib->IntValue();
					}
					else if (name == "x2")
					{
						x2 = attrib->IntValue();
					}
					else if (name == "y1")
					{
						y1 = attrib->IntValue();
					}
					else if (name == "y2")
					{
						y2 = attrib->IntValue();
					}

					attrib = attrib->Next();
				}
				element = element->NextSiblingElement("rect");
			}

			internalCreate(imageName, fileName, x1, y1, x2, y2);
		}

		root = root->NextSiblingElement("Image");
	}
}

void ImageLoader::internalCreate(std::string key, std::string fileName, int x1, int y1, int x2, int y2)
{
	Display* display = Display::Acquire();

	if (x1 < 0)
	{
		x1 = 0;
	}
	if (x2 < 0)
	{
		x2 = display->GetWidth(fileName);
	}	
	if (y1 < 0)
	{
		y1 = 0;
	}	
	if (y2 < 0)
	{
		y2 = display->GetHeight(fileName);
	}

	display->LoadImageFromFile(fileName, key, x1, y1, x2, y2);
}