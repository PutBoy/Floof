#include "GameObject.h"

GameObject::GameObject(int x, int y)
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
void GameObject::Kill(){
	killed = true;
}

bool GameObject::Dead(){
	return killed;
}

bool GameObject::TestCollision(GameObject* other)
{
	bool isCollided = false;

	if ((mSizeY == -1 && mSizeX == -1) || (other->mSizeY == -1 && other->mSizeX == -1))
	{
		isCollided = false;
	}
	else 
	{
		int top1 = this->GetY() - mSizeY / 2 + this->mVelocityY;
		int top2 = other->GetY() - other->mSizeY / 2 + other->mVelocityY;

		int bottom1 = this->GetY() + mSizeY / 2 + this->mVelocityY;
		int bottom2 = other->GetY() + other->mSizeY / 2 + other->mVelocityY;

		int left1 = this->GetX() - mSizeX / 2 + this->mVelocityX;
		int left2 = other->GetX() - other->mSizeX / 2 + other->mVelocityX;

		int right1 = this->GetX() + mSizeX / 2 + this->mVelocityX;
		int right2 = other->GetX() + other->mSizeX / 2 + other->mVelocityX;

		if (bottom1 < top2) return false;        
		if (top1 > bottom2) return false;        
		if (right1 < left2) return false;        
		if (left1 > right2) return false;

		return true;
	
	}

    return (isCollided);
}
void GameObject::Update(){
	
	int newX = GetX();
	int newY = GetY();

	SetX(newX + mVelocityX);
	SetY(newY + mVelocityY);
}