/*  Written: 2012-12-04
 *  By: Sebastian Zander
 *	
 *	Class for a dynamic image to be rendered
 */

#ifndef _DEBUG_TEXT_JOB
#define _DEBUG_TEXT_JOB

#include "Job.h"
#include <string>

class DebugTextJob: public Job
{
public:
	DebugTextJob(const std::string& text, float x, float y);
	virtual ~DebugTextJob() {};

	virtual void Render();
private:
	std::string mText;
	float mX;
	float mY;

};

#endif