#include "GameObject.h"

struct Collision{
public:
enum Direction{UP,DOWN,LEFT,RIGHT};
Collision(GameObject* c0, Direction direction):mC0(c0),mDirection(direction){};
GameObject* GetGameObject(){return mC0;};
Direction GetDirection(){return mDirection;};
private:
	GameObject* mC0;
	Direction mDirection;
};