#pragma once
#include "tinyxml2.h"
#include "allegro5/allegro.h"
#include <string>
#include <unordered_map>
#include <iostream>

class Textures
{
private:
	void parseSubtexturesAndAnimations(tinyxml2::XMLElement* child, bool isAnimation = false, std::string animationName = "");
	Textures();
	~Textures();
public:
	//Singleton
	Textures(Textures const&) = delete;
	void operator=(Textures const&) = delete;
	static Textures &getInstance();
	
	//Functionality
	std::vector<ALLEGRO_BITMAP*> atlases;
	std::unordered_map<std::string, ALLEGRO_BITMAP*> textures;
	std::unordered_map<std::string, std::vector<ALLEGRO_BITMAP*>> animations;
	void loadTexturesFromAtlas(const std::string s);
};