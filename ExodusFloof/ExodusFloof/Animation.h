/*  Written: 2012-11-30
 *  By: Sebastian Zander
 *	
 *	Class to store info for a config-loaded animation.
 */


#ifndef _ANIMATION_H
#define _ANIMATION_H

class Animation
{
public:
	Animation(int frames = 0): mFrames(frames) {};

	int GetFrames() const {return mFrames;};
private:

	int mFrames;
};

#endif