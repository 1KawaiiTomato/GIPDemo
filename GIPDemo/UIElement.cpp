#include "UIElement.h"



void UIElement::render()
{
	if (this->texture) {
		float x = al_get_display_width(al_get_current_display()) * relativeX;
		float y = al_get_display_height(al_get_current_display()) * relativeY;

		//std::cout << "x: " << x << "\ny: " << y << "\ntexture: " << texture << std::endl;

		al_draw_bitmap(texture, x, y, 0);

	}
}

std::string UIElement::getType()
{
	return "Element";
}

UIElement::UIElement()
{
}

UIElement::UIElement(std::string texturePath, float x, float y)
{
	this->relativeX = x;
	this->relativeY = y;
	this->isAnimated = false;
	this->texture = al_load_bitmap(texturePath.c_str());
	
	if (!texture) {
		al_show_native_message_box(al_get_current_display(), "Error", "Error", "UIEelement texture not loaded", 0, 0);
	}

	this->relativeWidth = al_get_bitmap_width(texture);
	this->relativeHeight = al_get_bitmap_height(texture);
}


UIElement::~UIElement()
{
}
