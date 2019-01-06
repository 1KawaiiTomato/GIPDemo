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

void World::setTile(int x, int y, Terrain * t)
{
	tiles[x][y] = t;
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
		tiles[count % width][std::floor(count / width)] = &terrainTypes[terrainIDs[indexValue]];
	}
	file.close();
}

void World::init()
{
	loadMapCSV("Data/world.csv");
}

void World::render(Camera *c)
{
	for (int i = std::ceil(c->camX/16 - c->half_optimised_render_width); i < std::ceil(c->camX/16 + c->half_optimised_render_width); i++) {
		for (int j = std::ceil(c->camY/16 - c->half_optimised_render_height); j < std::ceil(c->camY/16 + c->half_optimised_render_height); j++) {
			if (getTile(i, j) != NULL) {
				al_draw_scaled_bitmap(getTile(i, j)->getTexture()
					, 0, 0, 32, 32
					, (((i * 32) - c->camX) * c->zoom) + c->xOffset
					, (((j * 32) - c->camY) * c->zoom) + c->yOffset
					, 32 * c->zoom, 32 * c->zoom, 0);
			}
		}
	}
	/*for (int i = (int)c->camX - c->xOffset; i < (int)c->camX + 20 - c->xOffset; i++) {
		for (int j = 0; j < 20; j++) {
			if (getTile(i, j) != NULL) {
				al_draw_scaled_bitmap(getTile(i, j)->getTexture()
					, 0, 0, 32, 32
					, (((i * 32) - c->camX) * c->zoom) + c->xOffset
					, (((j * 32) - c->camY) * c->zoom) + c->yOffset
					, 32 * c->zoom, 32 * c->zoom, 0);
			}
		}
	}*/
}

void World::update()
{
}

World::World(Textures *t, std::string textureTypesPath)
{
	tinyxml2::XMLDocument XMLDoc;
	tinyxml2::XMLError eResult = XMLDoc.LoadFile(textureTypesPath.c_str());
	if (eResult != tinyxml2::XML_SUCCESS) { std::cout << "texture types xml failed to load."; };

	tinyxml2::XMLElement *Root = XMLDoc.FirstChildElement("TerrainTypes");

	//Initialize all terraintypes and create map on id.
	for (tinyxml2::XMLElement* child = Root->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		std::string name = child->Attribute("name");
		std::string texture = child->Attribute("texture");
		int power = child->IntAttribute("power", 3);
		bool solid = child->BoolAttribute("isSolid", true);
		int id = child->IntAttribute("id");
		std::cout << name << ": " << texture << std::endl;
		Terrain terr = Terrain(t->textures[texture], power, solid);
		terrainTypes[name] = terr;
		terrainIDs[id] = name;
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
