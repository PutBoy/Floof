#ifndef LEVEL_CREATOR_H_
#define LEVEL_CREATOR_H_
/*	LevelManager is responsible for creating the levels.
 *
 */

#include <vector>

class Floof;

class LevelCreator
{
public:
	LevelCreator(size_t tilesX, size_t tilesY);
	std::vector<Floof*>::iterator iterBegin();
	std::vector<Floof*>::iterator iterEnd();

private:
	void internalCreateLevel(size_t tilesX, size_t tilesY);
	std::vector<Floof*> floofs;
};

#endif