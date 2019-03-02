#pragma once
#include "tinyxml2.h"
#include "allegro5/allegro.h"
#include <string>
#include <unordered_map>
#include <iostream>

class Textures
{
private:
	Textures();
	~Textures();
public:
	//Singleton
	Textures(Textures const&) = delete;
	void operator=(Textures const&) = delete;
	static Textures &getInstance();
	
	//Functionality
	std::vector<ALLEGRO_BITMAP*> atlasses;
	std::unordered_map<std::string, ALLEGRO_BITMAP*> textures;
	void loadTexturesFromAtlas(const std::string s);
};