#pragma once
#include "allegro5/allegro.h"
#include "Terrain.h"
#include <vector>
#include "Camera.h"

class World
{
private:
	Terrain* tiles[100][20];
	Terrain grassTerrain;
public:
	Terrain* getTile(int x, int y);
	void init();
	void render(Camera *c);
	void update();
	World(Textures *t);
	World();
	~World();
};

