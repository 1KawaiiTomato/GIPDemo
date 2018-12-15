#pragma once
#include "UIElement.h"
#include <vector>
#include <unordered_map>

class Panel :
	public UIElement
{
private:
	float speed;
public:
	static void scroll(UIElement* p);
	static void wobble(UIElement *p);

	std::vector<std::function<void(UIElement*)>> animations;

	std::string getType() override;
	void update();

	Panel(std::string texturePath, float x, float y, std::vector<std::function<void(UIElement*)>> functions, std::unordered_map<std::string, float> values);
	Panel(std::string texturePath, float x, float y);
	Panel();
	~Panel();
};

