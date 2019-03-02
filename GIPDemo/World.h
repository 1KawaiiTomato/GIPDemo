#pragma once
#include "allegro5/allegro.h"
#include "MonsterManager.h"
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
	void setTile(int x, int y, Terrain *t);
	World(std::string textureTypesPath);
	void loadMapCSV(std::string path);
	Terrain* getTile(int x, int y);
	MonsterManager monsterManager;
	void render(Camera *c);
	void update();
	void init();
	World();
	~World();
};