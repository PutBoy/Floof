/*	The statehandler handles states. It saves its state in a stack of shared_ptr's
 *
 */

#ifndef _STATE_HANDLER_H
#define _STATE_HANDLER_H

#include <stack>
#include <memory>
#include "State.h"

class StateHandler
{
public:
	StateHandler();

	void PushState(std::shared_ptr<State>);
	
	void Update();
	void Render();

private:
	std::stack<std::shared_ptr<State>> mStateStack;

	sf::Clock clock;	
	float msElapsed;	
	const float msUpdateRate;
};

#endif