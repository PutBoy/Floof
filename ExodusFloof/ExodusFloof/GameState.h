#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Display.h"
#include "EventTimer.h"
#include "Canvas.h"

class GameState
{
public:
	GameState();
	virtual ~GameState();
	virtual void Start() = 0;

protected:
	virtual void Update(int frame) = 0;
	virtual void Render() = 0;

	void StartLoop(double FPS = 60);

	void Kill() { running = false; };

	Display* GetDisplay() { return display; };

private:
	bool running;

	Canvas* canvas;
	Display* display;
	EventTimer FPSTimer;
	SFMLWindow* window;
};
#endif