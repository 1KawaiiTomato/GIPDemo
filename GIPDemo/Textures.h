#pragma once
#include "tinyxml2.h"
#include "allegro5/allegro.h"
#include <string>
#include <unordered_map>
#include <iostream>

class Textures
{
public:
	std::vector<ALLEGRO_BITMAP*> atlasses;
	std::unordered_map<std::string, ALLEGRO_BITMAP*> textures;
	void loadTexturesFromAtlas(const std::string s);
	Textures();
	~Textures();
};