#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "InputStrategy.h"
#include "Input.h"
#include <fstream>
#include "AngleVec.h"


enum KeyBind {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_JUMP, KEY_FIRE,KEY_PUSH};

class Player: public GameObject
{
public:
	Player(Input& input, int x, int y, int playerNumber);
	void Update();
	void Render();

 	void ReverseGravity();
	bool GetPush(){return push;};
	virtual void ResolveCollision(GameObject* other);


private:
	std::string mAction;

	AngleVec mAngleVec;

	void Fire();

	Input mInput;
	bool mJumping;
	bool mFalling;
	double acc;
	bool push;

	int mPlayerNumber;

	bool boxCollided;

	int gravityModifier;

	bool postDeath;
	int blink;

	int lives;

	void Hurt();

};

#endif