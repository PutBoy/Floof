#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Canvas.h"
#include "ColliderComponent.h"

#include <vector>
#include <string>

struct Collision;
class GameObject{
public:
	GameObject(double x, double y, double weigth);
	~GameObject();

	double GetX() {return mX;};
	double GetY() {return mY;};

    void SetX(double newX) {mX = newX;};
	void SetY(double newY) {mY = newY;};

	void SetSizeX(int size) {mSizeX = size;};
	int GetSizeX() {return mSizeX;};
	
	void SetSizeY(int size) {mSizeY = size;};
	int GetSizeY() {return mSizeY;};

	void SetVelocityX(double velocityX){mVelocityX = velocityX;};
	double GetVelocityX(){return mVelocityX;};

	void SetVelocityY(double velocityY){mVelocityY = velocityY;};
	double GetVelocityY(){return mVelocityY;};

	double GetWeight(){return mWeight;};

	virtual ColliderComponent* GetColliderComponent() = 0;

	virtual void Render() = 0;
	virtual void Update();

	Canvas* GetCanvas() {return canvas;};

	void Drop(GameObject*);
	GameObject* GetNextDrop();
	Collision* GetNextCollision();
	void Kill();
	
	bool Dead();

	virtual void ReverseGravity() { };
	void PushCollision(Collision* collision);
	bool IsID(std::string ID) {return ID == mID;};
	void SetID(std::string ID) {mID = ID;};

private:	
	
	std::vector<GameObject*> drops;
	std::vector<Collision*> collisions;

	double mX;
	double mY;

	bool killed;

	int mSizeX;
	int mSizeY;

	double mVelocityX;
	double mVelocityY;

	std::string mID;

	double mWeight;
protected:
	

	Canvas* canvas;

};

#endif