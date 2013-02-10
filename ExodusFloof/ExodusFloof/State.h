#ifndef _STATE_H
#define _STATE_H

#include "Display.h"
#include "Canvas.h"
#include "SFMLWindow.h"

class State
{
public:
	State();
	virtual ~State() {};

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual bool IsAlive() = 0;

	virtual void Kill() = 0;
protected:
	Canvas* GetCanvas() {return mCanvas;};
	Display* GetDisplay() {return mDisplay;};
	SFMLWindow* GetWindow() {return mWindow;};
private:
	Canvas* mCanvas;
	Display* mDisplay;
	SFMLWindow* mWindow;

};
#endif