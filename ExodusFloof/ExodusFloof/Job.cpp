#include "Job.h"

Job::~Job(){}

Display* Job::GetDisplay()
{
	return Display::Acquire();
}