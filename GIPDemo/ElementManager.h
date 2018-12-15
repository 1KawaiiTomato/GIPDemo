#pragma once
#include <iostream>
#include <map>
#include <string>
#include "Button.h"
#include "Panel.h"

class ElementManager
{
private:
	ALLEGRO_COLOR white;
	std::multimap<std::string, UIElement*> elements;
	ALLEGRO_EVENT_QUEUE *EQ;
public:
	void pause();
	void start();
	void deleteElements();
	void update();
	void render();
	void addElement(UIElement *e);
	void addElement(UIElement *e, std::string);
	std::multimap<std::string, UIElement*>* getElements();
	ElementManager();
	~ElementManager();
};

