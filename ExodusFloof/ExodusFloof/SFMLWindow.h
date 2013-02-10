/*  Written: 2012-11-15 12.00.
 *  By: Oskar Nehro.
 *	Last Changed: 2012-11-19 13.59.
 *	Class to create a window.
 */
#ifndef _SFMLWINDOW_H
#define _SFMLWINDOW_H
#include <SFML\Graphics.hpp>
//Singelton class
class SFMLWindow{
public:
   /*
	*This function destroys the instances of SFMLWindow.
	*/
	static void Destroy();
   /*
	*Creates a new instances of SFMLWindow if there is no other instances of SFMLWindow.
	*Takes a integer for the height and width of the window. It also takes a string title for the namn of the window.
	*/
	static SFMLWindow* Init(int width, int height, std::string title);
   /*
	*This function returns the instances of SFMLWindow if the is one else it returns a null pointer.
	*/
	static SFMLWindow* Acquire();	
	int WindowOpen();
   /*
	*Returns the window if you need to add a object to it.
	*/
	sf::RenderWindow& GetWindow() {return mWindow;}	
private:
   /*
	*Konstruktor to create a new window. Can't be called from the outside as this class is a singelton class.
	*/
	SFMLWindow(int width, int height,std::string title);
   /*
	*Have the window name and are need if you want to add a object to the window.
	*/
	sf::RenderWindow mWindow;
   /*
	*A variabel of type SFMLWindow. Is a null pointer from the start if there is no instances of SFMLWindow.
	*/
	static SFMLWindow* singletonSFMLWindow;
};
#endif