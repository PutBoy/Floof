#include "GameState.h"

GameState::GameState()
{
	running = true;
	display = Display::Acquire();
	window = SFMLWindow::Acquire();
	canvas = Canvas::Aquire();
}

GameState::~GameState()
{
}

void GameState::StartLoop(double FPS)
{
	bool render = false;
	running = true;

	int frame = 0;

	FPSTimer.SetTickLength(1000.0 / 60);
	FPSTimer.Reset();

	while (window->WindowOpen() && running)
	{

		if (FPSTimer.ReadTick())
		{
			FPSTimer.AddTick();
			
			frame++;
			
			Update(frame);

			render = true;
		}
		
		if (render && !FPSTimer.ReadTick())
		{

			display->Clear();

			Render();

			canvas->Render();

			display->Flip();
			render = false;
		}

	}
}