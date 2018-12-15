#pragma once
#include "UIElement.h"

class Button :
	public UIElement
{
public:
	ALLEGRO_BITMAP *textures[2];
	std::string getType() override;
	Button();
	Button(std::vector<std::string> texturePath, float x, float y, void(*function)());
	~Button();
};

