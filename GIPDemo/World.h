#pragma once
#include "allegro5/allegro.h"
#include "Terrain.h"
#include <vector>
#include "Camera.h"

class World
{
private:
	std::vector<std::vector<Terrain*>> tiles;
	std::unordered_map<std::string, Terrain> terrainTypes;
	std::unordered_map<int, std::string> terrainIDs;
public:
	Terrain* getTile(int x, int y);
	void loadMapCSV(std::string path);
	void init();
	void render(Camera *c);
	void update();
	World(Textures *t, std::string textureTypesPath);
	World();
	~World();
};