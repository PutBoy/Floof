#ifndef _JOB_H
#define _JOB_H
#include "Display.h"

class Job
{
public:
	virtual void Render()=0;
	virtual ~Job();

protected:
	Display* GetDisplay();
};

#endif