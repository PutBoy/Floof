#include "Game.h"

#include <cstdlib>
#include <sstream>
#include "Player.h"
#include "Config.h"
#include "Box.h"
#include "Config.h"
#include "Input.h"
#include "StrategyKeysAndMouse.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Start()
{
	objects.push_back(new Player(Input(new StrategyKeysAndMouse()), 400, 400, 0));

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
	//Check Collisions
	for(int i = 0; i < objects.size(); i++)
	{
		for(int j = i; j < objects.size(); j++)
		{
			if (i != j)
			{
				if (objects[i]->TestCollision(objects[j]))
				{
					objects[i]->ResolveCollision(objects[j]);
					objects[j]->ResolveCollision(objects[i]);
				}
			}
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