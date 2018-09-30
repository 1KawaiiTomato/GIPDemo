#include "World.h"



Terrain * World::getTile(int x, int y)
{
	return tiles[x][y];
}

void World::init()
{
	for (int i = 0; i < 100; i++) {
		tiles[i][0] = &grassTerrain;
	}
}

void World::render()
{
	for (int i = 0; i < 100; i++) {
		al_draw_bitmap(getTile(i,0)->getTexture(), i * 32, 0, 0);
	}
}

void World::update()
{
}

World::World(Textures *t) : grassTerrain(t->textures["grass"])
{
}

World::World()
{
}


World::~World()
{
}
