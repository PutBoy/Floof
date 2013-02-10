/*  Written: 2012-11-11
 *  By: Oskar Nehro
 *	Last Changed: 2012-11-15
 *	Class to load and paint images to the window
 */
#ifndef _DISPLAY_H
#define _DISPLAY_H
#include <SFML\Graphics.hpp>
#include <map>
#include "SFMLWindow.h"

class Display{
public:	
	static void Destroy();
	static Display* Acquire();		
	void LoadImageFromFile(const std::string& filename, const std::string& key, int x1, int y1, int x2, int y2);

	void DrawImage(const std::string& key, float x, float y, float angle, sf::Vector2i center);
	void DrawImage(const std::string& key, float x, float y);
	void Flip();
	void Clear();

	int GetHeight(const std::string& filename);
	int GetWidth(const std::string& filename);

	void DrawText(const std::string& text, int x, int y);
private:
	Display();
	void StartLoop();
	static Display* singletonDisplay;
	SFMLWindow* GetSFMLWindow();
	std::map <std::string, sf::Sprite*> mSpriteMap;
	std::map <std::string, sf::Texture*> mTextureMap;
};
#endif