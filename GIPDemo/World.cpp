#include "World.h"



Terrain * World::getTile(int x, int y)
{
	return tiles[x][y];
}

void World::init()
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 20; j++) {
			tiles[i][j] = &grassTerrain;
		}
	}
}

void World::render(Camera *c)
{
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 20; j++) {
			al_draw_scaled_bitmap(getTile(i, j)->getTexture()
				, 0, 0, 32, 32, (((i * 32) - c->camX) * c->zoom) + c->xOffset
				, ((j * 32) - c->camY)*c->zoom + c->yOffset
				, 32 * c->zoom, 32 * c->zoom, 0);
		}
	}
	std::cout << "camX: " << c->camX << "\n camY: " << c->camY << std::endl;
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
