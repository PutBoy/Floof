#include "CharacterLoader.h"


void CharacterLoader::Load(TiXmlDocument& doc)
{
	TiXmlElement* root = doc.FirstChildElement("Body");
	root = root->FirstChildElement("Character");
	while (root)
	{
		TiXmlAttribute* attribute = root->FirstAttribute();
		std::string str = attribute->Name();
		if (str == "name")
		{
			std::string characterName = attribute->Value();
			std::string fileName;
			int x1 = -1, x2 = -1, y1 = -1, y2 = -1;
			TiXmlElement* element = root->FirstChildElement("a");
			
			while (element)
			{
				TiXmlAttribute* attrib = element->FirstAttribute();
				while (attrib)
				{
					std::string name = attrib->Name();
					std::string value = attrib->Value();
					addValue(characterName, name, value);

					attrib = attrib->Next();
				}
				element = element->NextSiblingElement("a");
			}

		}

		root = root->NextSiblingElement("Character");
	}
}

void CharacterLoader::addValue(const std::string& character, const std::string& tag, const std::string& value)
{
	valueMap.insert(std::pair<std::string, std::string>(character + "/" + tag, value));
}

std::string CharacterLoader::getString(const std::string& character, const std::string& tag) const
{
	if (valueMap.count(character + "/" + tag))
		return valueMap.at(character + "/" + tag);
	else
		return "";
}

int CharacterLoader::getInt(const std::string& character, const std::string& tag) const
{
	if (valueMap.count(character + "/" + tag))
		return atoi(valueMap.at(character + "/" + tag).c_str());
	else
		return 0;
}

double CharacterLoader::getDouble(const std::string character, const std::string& tag) const
{
	if (valueMap.count(character + "/" + tag))
		return atof(valueMap.at(character + "/" + tag).c_str());
	else
		return 0;
}

bool CharacterLoader::isLoaded(const std::string& character, const std::string& tag) const
{
	return valueMap.count(character + "/" + tag) == 1;
}