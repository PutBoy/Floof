#include "SFMLWindow.h"
#include "Game.h"
#include "Config.h"
#include <Box2d\Box2D.h>

int main()
{

	SFMLWindow* window = SFMLWindow::Init(1920,1080, "apa");
		
	Config config;
	config.Load("config.xml");

	Game game;
	game.Start();

	SFMLWindow::Destroy();
}