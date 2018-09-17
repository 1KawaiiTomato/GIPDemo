#pragma once
#include "tinyxml2.h"
#include "allegro5/allegro.h"
#include <string>
#include <unordered_map>
#include <iostream>

namespace Textures
{
	static ALLEGRO_BITMAP *atlas;
	static std::unordered_map<std::string, ALLEGRO_BITMAP*> textures;
	static void loadTexturesFromAtlas(std::string s) {
		tinyxml2::XMLDocument xmlDoc;
		xmlDoc.LoadFile(s.c_str());
		tinyxml2::XMLElement * pRoot = xmlDoc.FirstChildElement();
		atlas = al_load_bitmap(pRoot->Attribute("imagePath"));
		for (tinyxml2::XMLElement* child = pRoot->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {

			std::cout << atlas << std::endl;
			int x = child->IntAttribute("x");
			int y = child->IntAttribute("y");
			int w = child->IntAttribute("width");
			int h = child->IntAttribute("height");
			std::string name = child->Attribute("name");
			textures[name] = al_create_sub_bitmap(atlas, x, y, w, h);
		}
	}
};