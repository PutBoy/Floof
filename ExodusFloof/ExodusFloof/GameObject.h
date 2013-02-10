#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include "Canvas.h"

#include <vector>
#include <string>

class GameObject{
public:
	GameObject(int x, int y);
	
	int GetX() {return mX;};
	int GetY() {return mY;};

    void SetX(int newX) {mX = newX;};
	void SetY(int newY) {mY = newY;};

	void SetSizeX(int size) {mSizeX = size;};
	int GetSizeX() {return mSizeX;};
	
	void SetSizeY(int size) {mSizeY = size;};
	int GetSizeY() {return mSizeY;};

	virtual void Render() = 0;
	virtual void Update();

	Canvas* GetCanvas() {return canvas;};

	void Drop(GameObject*);
	GameObject* GetNextDrop();
	void Kill();
	
	bool Dead();

	virtual void ReverseGravity() { };

	bool TestCollision(GameObject* other);

	virtual void ResolveCollision(GameObject* other) {};

	bool IsID(std::string ID) {return ID == mID;};
	void SetID(std::string ID) {mID = ID;};

private:	
	
	std::vector<GameObject*> drops;

	int mX;
	int mY;

	bool killed;

	int mSizeX;
	int mSizeY;

	std::string mID;
protected:
	double mVelocityX;
	double mVelocityY;

	Canvas* canvas;

};

#endif