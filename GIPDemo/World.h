#pragma once
#include "allegro5/allegro.h"
#include "Terrain.h"
#include <vector>
#include "Camera.h"

class World
{
private:
	std::vector<std::vector<Terrain*>> tiles;
	std::unordered_map<int, std::string> terrainIDs;
public:
	std::unordered_map<std::string, Terrain> terrainTypes;
	Terrain* getTile(int x, int y);
	void setTile(int x, int y, Terrain *t);
	void loadMapCSV(std::string path);
	void init();
	void render(Camera *c);
	void update();
	World(std::string textureTypesPath);
	World();
	~World();
};