#include "Display.h"

Display* Display::singletonDisplay=nullptr;

Display* Display::Acquire(){
	if(singletonDisplay==nullptr)
		singletonDisplay = new Display();
		return singletonDisplay;
}

void Display::LoadImageFromFile(const std::string& filename, const std::string& key, int x1, int y1, int x2, int y2){
	sf::Texture* tmpTexture;
	
	if(mTextureMap.count(filename)==0)
	{
		tmpTexture = new sf::Texture;
		tmpTexture->loadFromFile(filename);
		mTextureMap.insert(std::pair<std::string,sf::Texture*>(filename,tmpTexture));
	}
	else
	{
		tmpTexture = mTextureMap[filename];
	}
	
	sf::Sprite* tmpSprite = new sf::Sprite(*tmpTexture,sf::IntRect(x1,y1,x2-x1,y2-y1));

	mSpriteMap.insert(std::pair<std::string, sf::Sprite*>(key, tmpSprite));
}

void Display::DrawImage(const std::string& key, float x, float y){
	if (mSpriteMap.count(key) == 1)
	{
		sf::Sprite tmpSprite(*mSpriteMap[key]);
		tmpSprite.setPosition(x, y);
		GetSFMLWindow()->GetWindow().draw(tmpSprite);
	}
}

Display::Display(){	
	GetSFMLWindow()->GetWindow().setMouseCursorVisible(true);
}

void Display::Destroy(){
	delete singletonDisplay;
}

void Display::Clear(){
	GetSFMLWindow()->GetWindow().clear(sf::Color(0,0,0));
}

void Display::Flip(){
	GetSFMLWindow()->GetWindow().display();
}

SFMLWindow* Display::GetSFMLWindow(){
	return SFMLWindow::Acquire();
}

int Display::GetHeight(const std::string& filename)
{
	sf::Texture* tmpTexture;
	
	if(mTextureMap.count(filename)==0)
	{
		tmpTexture = new sf::Texture;
		tmpTexture->loadFromFile(filename);
		mTextureMap.insert(std::pair<std::string,sf::Texture*>(filename,tmpTexture));
	}
	else
	{
		tmpTexture = mTextureMap.at(filename);
	}

	return tmpTexture->getSize().y;
}

int Display::GetWidth(const std::string& filename)
{
	sf::Texture* tmpTexture;
	
	if(mTextureMap.count(filename)==0)
	{
		tmpTexture = new sf::Texture;
		tmpTexture->loadFromFile(filename);
		mTextureMap.insert(std::pair<std::string,sf::Texture*>(filename,tmpTexture));
	}
	else
	{
		tmpTexture = mTextureMap[filename];
	}

	return tmpTexture->getSize().x;
}

void Display::DrawText(const std::string& text, int x, int y)
{
	sf::Text sfText = sf::Text(text);
	sfText.setPosition(x, y);
	GetSFMLWindow()->GetWindow().draw(sfText);
}