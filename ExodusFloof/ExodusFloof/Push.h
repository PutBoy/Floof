/*  Written: 2012-12-04
 *  By: Sebastian Zander
 *	
 *	Class for a dynamic image to be rendered
 */

#ifndef PUSH_H_
#define PUSH_H_

#include "GameObject.h"
#include "NonCollidable.h"

class Push: public GameObject
{
public:
	Push(int x, int y, GameObject* pusherObj);

	virtual ColliderComponent* GetColliderComponent() {return new NonCollidable(this);};

	virtual void Render(){};
	virtual void Update();
private:
	int mY;
	int mX;
	int mOriginX;
	int mOriginY;
	int mFrameCount;

	GameObject* mPusherObj;
};

#endif