#include "Button.h"


std::string Button::getType()
{
	return "Button";
}

Button::Button()
{
}

Button::Button(std::vector<std::string> texturePath, float x, float y, void(*function)()) : UIElement(texturePath[0], x, y)
{
	this->onClick = function;
	this->textures[0] = al_load_bitmap(texturePath[0].c_str());
	this->textures[1] = al_load_bitmap(texturePath[1].c_str());

	/*
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	std::cout << this->relativeWidth << std::endl;
	*/
}


Button::~Button()
{
}