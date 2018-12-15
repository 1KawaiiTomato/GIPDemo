#include "Panel.h"



void Panel::scroll(UIElement *p)
{
	p->relativeX -= p->values["sSpeed"];
	if (p->relativeX * al_get_display_width(al_get_current_display()) + p->relativeWidth <= 0 + al_get_display_width(al_get_current_display()) || p->relativeX > 0) {
		p->values["sSpeed"] = -p->values["sSpeed"];
		p->relativeX -= p->values["sSpeed"];
	}
}

void Panel::wobble(UIElement * p)
{
	p->values["wAngle"]+=p->values["wSpeed"];
	p->relativeY = p->relativeY - ((sin(p->values["wAngle"]) * p->values["wHeight"]));
}

std::string Panel::getType()
{
	return "Panel";
}

Panel::Panel(std::string texturePath, float x, float y, std::vector<std::function<void(UIElement*)>> functions, std::unordered_map<std::string, float> values) : UIElement(texturePath, x, y)
{
	this->values = values;
	this->animations = functions;
	this->isAnimated = true;
	this->speed = speed;
}

Panel::Panel(std::string texturePath, float x, float y) : UIElement(texturePath, x, y)
{
}

void Panel::update()
{
	for (auto it : animations) {
		it(this);
	}
}

Panel::Panel()
{
}


Panel::~Panel()
{
}
