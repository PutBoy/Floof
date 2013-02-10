#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameObject.h"

class Game : public GameState
{
public:
	Game();
	void Start();
	virtual ~Game();

protected:

	void Update(int frame);
	void Render();

private:
	std::vector<GameObject*> objects;

};
#endif