#pragma once
#include "allegro5/allegro.h"
#include "Terrain.h"
#include <vector>
#include "Camera.h"

class World
{
private:
	std::vector<std::vector<Terrain*>> tiles;
	Terrain grassTerrain;
	Terrain airTerrain;
	Terrain cobbleTerrain;
	Terrain woodTerrain;
	Terrain dirtTerrain;
public:
	Terrain* getTile(int x, int y);
	void loadMapCSV(std::string path);
	void init();
	void render(Camera *c);
	void update();
	World(Textures *t);
	World();
	~World();
};

