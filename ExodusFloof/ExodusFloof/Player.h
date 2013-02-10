#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "InputStrategy.h"
#include "Input.h"
#include <fstream>
#include "AngleVec.h"
#include "Collidable.h"


enum KeyBind {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, KEY_JUMP, KEY_FIRE,KEY_PUSH};

class Player: public GameObject
{
public:
	Player(Input& input, int x, int y, int playerNumber);
	void Update();
	void Render();

 	void ReverseGravity();
	bool GetPush(){return push;};

	ColliderComponent* GetColliderComponent(){return new Collidable(this);};


private:
	std::string mAction;

	AngleVec mAngleVec;

	void Fire();

	Input mInput;
	bool mJumping;
	double acc;
	bool push;

	int mPlayerNumber;

	bool boxCollided;

	int gravityModifier;

	bool postDeath;
	int blink;

	int lives;

	void Hurt();

	int mAnimFrame;

	double jumpVelo;
	double walkSpeed;
};

#endif