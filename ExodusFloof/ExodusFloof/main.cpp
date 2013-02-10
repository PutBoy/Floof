#include "SFMLWindow.h"
#include "Game.h"
#include "Config.h"
#include <Box2d\Box2D.h>
#include "StateHandler.h"
#include "Game.h"
#include "Canvas.h"
#include "Display.h"

int main()
{

	SFMLWindow* window = SFMLWindow::Init(1920,1080, "apa");
	Display* display = Display::Acquire();
	Canvas* canvas = Canvas::Aquire();

	Config config;
	config.Load("config.xml");

	StateHandler stateHandler;
	stateHandler.PushState(std::make_shared<Game>());

	while (window->WindowOpen())
	{

		stateHandler.Update();

		display->Clear();

		stateHandler.Render();

		canvas->Render();

		display->Flip();

	}

	SFMLWindow::Destroy();
}