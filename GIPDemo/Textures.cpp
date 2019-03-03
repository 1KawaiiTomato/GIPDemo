#include "Textures.h"

Textures & Textures::getInstance()
{
	static Textures instance;
	return instance;
}

void Textures::loadTexturesFromAtlas(std::string s)
{
	//open xml file
	tinyxml2::XMLDocument xmlDoc;
	xmlDoc.LoadFile(s.c_str());

	//Load in the atlas
	tinyxml2::XMLElement * pRoot = xmlDoc.FirstChildElement();
	Textures::atlasses.push_back(al_load_bitmap(pRoot->Attribute("imagePath")));

	//Parse xml and create subtextures accordingly
	parseSubtexturesAndAnimations(pRoot->FirstChildElement());
}

void Textures::parseSubtexturesAndAnimations(tinyxml2::XMLElement* child, bool isAnimation, std::string animationName)
{
	for (; child != NULL; child = child->NextSiblingElement()) {
		std::string n = child->Name();

		if (n == "Animation") {
			std::cout << child->Name() << std::endl;
			parseSubtexturesAndAnimations(child->FirstChildElement(), true, child->Attribute("name"));
		}
		int x = child->IntAttribute("x");
		int y = child->IntAttribute("y");
		int w = child->IntAttribute("width");
		int h = child->IntAttribute("height");
		if (!isAnimation) {
			std::string name = child->Attribute("name");
			Textures::textures[name] = al_create_sub_bitmap(atlasses.back(), x, y, w, h);
		}else
			Textures::animations[animationName].push_back(al_create_sub_bitmap(atlasses.back(), x, y, w, h));
	}
}

Textures::Textures()
{
}

Textures::~Textures()
{
}
