#include "Game.h"

#include <cstdlib>
#include <sstream>
#include "Player.h"
#include "Config.h"
#include "Box.h"
#include "Config.h"
#include "Input.h"
#include "StrategyKeysAndMouse.h"
#include "LevelCreator.h"
#include "Border.h"
#include "StrategyKeys.h"
#include "Floof.h"

Game::Game()
	:mBoxWorld(b2Vec2(0.f, 10.f))
{
	worldTimer.restart();
}

Game::~Game()
{

}

void Game::Start()
{
	LevelCreator level(20, 9, mBoxWorld);
	
	for (auto iter = level.iterBegin(); iter != level.iterEnd(); ++iter)
	{
		objects.push_back(*iter);
	}
	
	objects.push_back(new Player(Input(new StrategyKeysAndMouse()), 400, 400, 1, mBoxWorld));
	//objects.push_back(new Player(Input(new StrategyKeys()), 700, 400, 0, mBoxWorld));

	//objects.push_back(new Box(500, 300, 1));
	objects.push_back(new Box(600, 400, 1, mBoxWorld));

	for (int i=0; i<10; i++)
	{
		//objects.push_back(new Border(i*64, false)); 
		//objects.push_back(new Border(i*64, true)); 
	}

	StartLoop();
}

void Game::Render()
{


	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Render();
	}

}

void Game::Update(int frame)
{

	float32 timeStep = worldTimer.restart().asMilliseconds();
	int32 velocityIterations = 6;
	int32 positionIterations = 2;

	mBoxWorld.Step(timeStep, velocityIterations, positionIterations);

	sf::RenderWindow& window=SFMLWindow::Acquire()->GetWindow();
	sf::View view(window.getView());
	//view.move(1,0);
	window.setView(view);

	//Collider
	/*for(int i = 0; i < objects.size(); i++)
	{
		collider.Push(objects[i]->GetColliderComponent());
	}
	collider.Collide();
	collider.Clear();*/

	//Update objects
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->Update();
	}

	//Retrieve drops
	for(int i =0; i < objects.size(); i++)
	{
		GameObject* tmp = objects[i]->GetNextDrop();

		while (tmp != nullptr)
		{
			objects.push_back(tmp);
			tmp = objects[i]->GetNextDrop();
		}
	}

	//Cull the dead
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->Dead())
		{
			GameObject* mov = objects.back();
			delete objects[i];
			objects[i] = mov;
			objects.pop_back();
			i--;
		}
	}

}