#include "SFMLWindow.h"
#include "Game.h"
#include "Config.h"

int main()
{

	SFMLWindow* window = SFMLWindow::Init(1366,768, "apa");
		
	Config config;
	config.Load("config.xml");

	Game game;
	game.Start();

	SFMLWindow::Destroy();
}