/*  Written: 2012-11-09
 *  By: Robbin Torstensson
 *	Last Changed: 2012-11-14
 *	Class to create add a image to get painted.
 */
#ifndef _SIMPLE_IMAGE_JOB_H
#define _SIMPLE_IMAGE_JOB_H
#include "Job.h"
#include "Display.h"
#include <iostream>

class SimpleImageJob:public Job
{
public:
	SimpleImageJob(std::string key,float x, float y);
	virtual ~SimpleImageJob();

	virtual void Render();
private:
	std::string mKey;
	float mX;
	float mY;
};

#endif