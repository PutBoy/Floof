#include "SFMLWindow.h"


SFMLWindow* SFMLWindow::singletonSFMLWindow=nullptr;

SFMLWindow* SFMLWindow::Init(int width, int height,std::string title){
	if (singletonSFMLWindow == nullptr)
	{
		singletonSFMLWindow = new SFMLWindow(width,height,title);	
	}
	else
	{
		return nullptr;
	}
	return singletonSFMLWindow;
}

SFMLWindow* SFMLWindow::Acquire(){
	if(singletonSFMLWindow!=nullptr)
		return singletonSFMLWindow;
	else
		return nullptr;
}

void SFMLWindow::Destroy(){
	delete singletonSFMLWindow;
}

SFMLWindow::SFMLWindow(int width, int height, std::string title){
	mWindow.create(sf::VideoMode(width,height,32),
		title, 
		sf::Style::Close);


}

int SFMLWindow::WindowOpen(){

	// Process events
	int evCount = 0;
    sf::Event tmp;
	
	while (mWindow.pollEvent(tmp))
    {
		evCount++;
        // Close window : exit
		if (tmp.type == sf::Event::Closed)
		{
			mWindow.close();
		}
	}
	
	if (evCount > 1)
		evCount = evCount;

	return mWindow.isOpen();
}
