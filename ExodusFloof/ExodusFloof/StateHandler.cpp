#include "StateHandler.h"
#include "SFMLWindow.h"

StateHandler::StateHandler()
	:msElapsed(0.f)	
	,msUpdateRate(10.f)
{

}

void StateHandler::PushState(std::shared_ptr<State> state)
{
	mStateStack.push(state);
}

void StateHandler::Update()
{
	if (mStateStack.empty())
	{
		SFMLWindow::Acquire()->GetWindow().close();
		return;
	}

	while (!mStateStack.top()->IsAlive())
	{
		mStateStack.pop();
		if (mStateStack.empty())
		{
			SFMLWindow::Acquire()->GetWindow().close();
			return;
		}
	}

	for (msElapsed += clock.restart().asMilliseconds(); msElapsed > msUpdateRate; msElapsed -= msUpdateRate)		
	{			
		mStateStack.top()->Update();		
	}
}

void StateHandler::Render()
{
	mStateStack.top()->Render();
}