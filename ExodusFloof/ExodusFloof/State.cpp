#include "State.h"

State::State()
{
	mDisplay = Display::Acquire();
	mWindow = SFMLWindow::Acquire();
	mCanvas = Canvas::Aquire();
}