#include "GameObject.h"


GameObject::GameObject(double x, double y, b2World& world)
	:mWorld(world)
{
	mX = x;
	mY = y;
	canvas = Canvas::Aquire();
	killed = false;
	mSizeX = -1;
	mSizeY = -1;

	mVelocityX = 0;
	mVelocityY = 0;


}

GameObject::~GameObject()
{
	for (size_t i = 0; i < drops.size(); i++)
	{
		delete drops[i];
	}
}

void GameObject::Drop(GameObject* drop){
	drops.push_back(drop);
}

GameObject* GameObject::GetNextDrop(){
	GameObject* ret;

	if(drops.size()==0)
		ret = nullptr;
	else
	{
		ret = drops.back();
		drops.pop_back();
	}

	return ret;
}
void GameObject::PushCollision(Collision* collision){
	collisions.push_back(collision);
}

Collision* GameObject::GetNextCollision(){
	Collision* colli;
	if(collisions.size()==0)
		colli = nullptr;
	else
	{
		colli = collisions.back();
		collisions.pop_back();
	}
	return colli;
}
void GameObject::Kill(){
	killed = true;
}

bool GameObject::Dead(){
	return killed;
}

void GameObject::Update(){
	
	int newX = GetX();
	int newY = GetY();

	SetX(newX + mVelocityX);
	SetY(newY + mVelocityY);
}