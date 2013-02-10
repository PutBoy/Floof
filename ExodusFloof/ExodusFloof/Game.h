#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "GameObject.h"
#include "CollisionHandler.h"
#include <Box2D/Dynamics/b2World.h>
#include <SFML\System\Clock.hpp>

class Game : public State
{
public:
	Game();
	virtual ~Game();

	void Update();
	void Render();

	virtual bool IsAlive();

	virtual void Kill();

private:
	b2World mBoxWorld;

	std::vector<GameObject*> objects;
	CollisionHandler collider;

	sf::Clock worldTimer;


};
#endif