#ifndef GAME_H
#define GAME_H

#include "GameState.h"
#include "GameObject.h"
#include "CollisionHandler.h"
#include <Box2D/Dynamics/b2World.h>
#include <SFML\System\Clock.hpp>

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
	b2World mBoxWorld;

	std::vector<GameObject*> objects;
	CollisionHandler collider;

	sf::Clock worldTimer;


};
#endif