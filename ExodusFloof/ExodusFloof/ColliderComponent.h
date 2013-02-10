#ifndef _COLLIDER_COMPONENT_H
#define _COLLIDER_COMPONENT_H
#include "CollisionHandler.h"

class GameObject;

class ColliderComponent
{
public:
	ColliderComponent(GameObject* object);
	virtual ~ColliderComponent(){};

	double GetWeight()const{return mWeight;};
	void SetWeight(double weight){mWeight=weight;};

	virtual void SetX(double x)=0;
	virtual void SetY(double y)=0;

	virtual void SetOtherX(double x, ColliderComponent* other)=0;
	virtual void SetOtherY(double y, ColliderComponent* other)=0;

	double GetX() const {return mX;};
	double GetY() const {return mY;};
	
	double GetSizeX() const {return mSizeX;};
	double GetSizeY() const {return mSizeY;};

	GameObject* GetObject() const{return mObject;};
protected:
private:
	GameObject* mObject;

	double mWeight;

	const double mX;
	const double mY;

	const int mSizeX;
	const int mSizeY;
};

#endif