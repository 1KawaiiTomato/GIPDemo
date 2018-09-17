#include "Textures.h"

/*
void Textures::loadTexturesFromAtlas(std::string s)
{
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(s.c_str());
	tinyxml2::XMLElement * pRoot = xmlDoc.FirstChildElement();
	Textures::atlas = al_load_bitmap(pRoot->Attribute("imagePath"));
	for (tinyxml2::XMLElement* child = pRoot->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
			std::cout << atlas << std::endl;
		int x = child->IntAttribute("x");
		int y = child->IntAttribute("y");
		int w = child->IntAttribute("width");
		int h = child->IntAttribute("height");
		std::string name = child->Attribute("name");
		Textures::textures[name] = al_create_sub_bitmap(atlas, x, y, w, h);
	}
}
*/