#include "World.h"
#include <fstream>


Terrain * World::getTile(int x, int y)
{
	if (x >= 0 && x < tiles.size()) {
		if (y >= 0 && y < tiles[x].size()) {
			return tiles[x][y];
		}
	}
	return NULL;
}

void World::loadMapCSV(std::string path)
{
	//open csv file
	std::ifstream file;
	file.open(path);

	std::string number;
	std::getline(file, number, ',');
	
	//Resize the 2 dimensional vector to fit our world: 
	//The first number is the width of the world
	int width = std::stoi(number);
	tiles.resize(width);

	//The second number is the height of the world
	std::getline(file, number, ',');
	int height = std::stoi(number);
	for (int i = 0; i < tiles.size(); i++) {
		tiles[i].resize(height);
	}

	//iterate numbers in csv file, keeping track of its position
	for (int count = 0; file.good(); count++) {
		std::getline(file, number, ',');
		int indexValue = std::stoi(number);
		switch (indexValue) {
		default: std::cout << "add\n"; break;
		case 0: tiles[count % width][std::floor(count / width)] = &airTerrain; break;
		case 1: tiles[count % width][std::floor(count / width)] = &grassTerrain; break;
		case 2: tiles[count % width][std::floor(count / width)] = &cobbleTerrain; break;
		case 3: tiles[count % width][std::floor(count / width)] = &woodTerrain; break;
		case 4: tiles[count % width][std::floor(count / width)] = &dirtTerrain; break;
		}
	}
	file.close();
}

void World::init()
{
	loadMapCSV("Data/testWorld.csv");
}

void World::render(Camera *c)
{
	for (int i = (int)c->camX/16 - 10; i < (int)c->camX/16 + 10; i++) {
		for (int j = 0; j < 20; j++) {
			int utilisedI = i;
			if (getTile(utilisedI, j) != NULL) {
				al_draw_scaled_bitmap(getTile(utilisedI, j)->getTexture()
					, 0, 0, 32, 32
					, (((i * 32) - c->camX) * c->zoom) + c->xOffset
					, (((j * 32) - c->camY) * c->zoom) + c->yOffset
					, 32 * c->zoom, 32 * c->zoom, 0);
			}
		}
	}
}

void World::update()
{
}

World::World(Textures *t) : grassTerrain(t->textures["grass"], 3, true),
							airTerrain(t->textures["air"], 0, false),
							cobbleTerrain(t->textures["cobble"], 6, true),
							woodTerrain(t->textures["wood"], 5, true),
							dirtTerrain(t->textures["dirt"], 3, true)
{
}

World::World()
{
}


World::~World()
{
}
