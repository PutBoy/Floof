#include "EventTimer.h"

EventTimer::EventTimer(double MSTick)
{
	timer = std::clock() * CLK_TCK;
	timerLength = MSTick * CLK_TCK;
}

EventTimer::EventTimer()
{
	timer = std::clock() * CLK_TCK;
	timerLength = 0;
}

EventTimer::~EventTimer()
{
	
}

bool EventTimer::ReadTick() const
{
	clock_t currentTime = std::clock() * CLK_TCK;
	
	if (currentTime > timer + timerLength)
	{
		return true;
	}

	return false;
}

void EventTimer::Reset()
{
	timer = std::clock() * CLK_TCK;
}

void EventTimer::AddTick()
{
	timer += timerLength;
}

void EventTimer::SetTickLength(double newMSTick, bool reset)
{
	timerLength = newMSTick * CLK_TCK;

	if (reset)
	{
		timer = std::clock() * CLK_TCK;
	}
}
