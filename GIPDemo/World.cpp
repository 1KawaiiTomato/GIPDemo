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
		case 0: tiles[count % width][std::floor(count / width)] = &terrainTypes["airBlock"]; break;
		case 1: tiles[count % width][std::floor(count / width)] = &terrainTypes["grassBlock"]; break;
		case 2: tiles[count % width][std::floor(count / width)] = &terrainTypes["cobbleBlock"]; break;
		case 3: tiles[count % width][std::floor(count / width)] = &terrainTypes["woodBlock"]; break;
		case 4: tiles[count % width][std::floor(count / width)] = &terrainTypes["dirtBlock"]; break;
		}
	}
	file.close();
}

void World::init()
{
	loadMapCSV("Data/world.csv");
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

/*World::World(Textures *t) : grassTerrain(t->textures["grass"], 3, true),
							airTerrain(t->textures["air"], 0, false),
							cobbleTerrain(t->textures["cobble"], 6, true),
							woodTerrain(t->textures["wood"], 5, true),
							dirtTerrain(t->textures["dirt"], 3, true)
{
}*/

World::World(Textures *t, std::string textureTypesPath)
{
	tinyxml2::XMLDocument XMLDoc;
	tinyxml2::XMLError eResult = XMLDoc.LoadFile(textureTypesPath.c_str());
	if (eResult != tinyxml2::XML_SUCCESS) { std::cout << "texture types xml failed to load."; };
	tinyxml2::XMLElement *Root = XMLDoc.FirstChildElement("TerrainTypes");
	for (tinyxml2::XMLElement* child = Root->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		std::string name = child->Attribute("name");
		std::string texture = child->Attribute("texture");
		int power = child->IntAttribute("power", 3);
		bool solid = child->BoolAttribute("isSolid", true);
		std::cout << name << ": " << texture << std::endl;
		Terrain terr = Terrain(t->textures[texture], power, solid);
		terrainTypes[name] = terr;
	}
	for (auto it : terrainTypes) {
		std::cout << it.first << ": " << it.second.getTexture() << std::endl;
	}
}

World::World()
{
}


World::~World()
{
}
