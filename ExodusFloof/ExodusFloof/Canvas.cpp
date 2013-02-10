#include "Canvas.h"

Canvas* Canvas::singletonInstance = nullptr;

Canvas* Canvas::Aquire()
{
	if (Canvas::singletonInstance == nullptr)
		Canvas::singletonInstance = new Canvas();

	return Canvas::singletonInstance;
}

void Canvas::Destroy()
{
	if (Canvas::singletonInstance != nullptr)
		delete Canvas::singletonInstance;
}

Canvas::Canvas(size_t maxLayers):
	layers(maxLayers)
{
}

void Canvas::AddNewJob(Job* job, size_t layer)
{
	if (layer >= layers.size())
		layer = layers.size() - 1;

	layers[layer].push_back(job);

}

void Canvas::Render()
{
	for (size_t i = 0; i < layers.size(); i++)
	{
		for (size_t j = 0; j < layers[i].size(); j++)
		{
			layers[i][j]->Render();
			delete layers[i][j];
		}
		layers[i].clear();
	}

	
}