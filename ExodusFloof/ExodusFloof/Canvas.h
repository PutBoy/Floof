/*  Written: 2012-11-10
 *  By: Sebastian Zander
 *	Last Changed 2012-11-14
 *	Class to create a new job and to call render function for all jobs
 */

#ifndef _CANVAS_H
#define _CANVAS_H

#include <vector>
#include "Job.h"
#include "Config.h"

//Singleton-klass
class Canvas
{
public:
	static Canvas* Aquire();
	static void Destroy();

	void AddNewJob(Job* job, size_t layer);
	void Render();
private:
	Canvas(size_t maxLayers = 10);

	static Canvas* singletonInstance;	

	std::vector< std::vector< Job* > > layers;

	Config mCfg; // must be here!
};
#endif