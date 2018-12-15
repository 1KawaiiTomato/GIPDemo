#include "ElementManager.h"



void ElementManager::pause()
{
	al_pause_event_queue(EQ, true);
}

void ElementManager::start()
{
	al_pause_event_queue(EQ, false);
}

void ElementManager::deleteElements()
{
	for (auto it : elements) {
		delete it.second;
	}
	elements.clear();
}

void ElementManager::update()
{
	float w, h;
	w = al_get_display_width(al_get_current_display());
	h = al_get_display_height(al_get_current_display());

	ALLEGRO_EVENT E;
	al_get_next_event(EQ, &E);
	if (E.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
		for (auto it : elements) {
			if (E.mouse.x > it.second->relativeX*w && E.mouse.x < it.second->relativeX*w + it.second->relativeWidth &&
				E.mouse.y > it.second->relativeY*h && E.mouse.y < it.second->relativeY*h + it.second->relativeHeight) {
				std::cout << it.second->getType();
				if (it.second->getType() == "Button") {
					static_cast<Button*>(it.second)->texture = static_cast<Button*>(it.second)->textures[1];
				}
			}
		}
	}
	else {
		if (E.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			for (auto it : elements) {
				if (it.second->getType() == "Button") {
					static_cast<Button*>(it.second)->texture = static_cast<Button*>(it.second)->textures[0];
					if (E.mouse.x > it.second->relativeX*w && E.mouse.x < it.second->relativeX*w + it.second->relativeWidth &&
						E.mouse.y > it.second->relativeY*h && E.mouse.y < it.second->relativeY*h + it.second->relativeHeight) {
						it.second->onClick();
					}
				}
			}
		}
	}
	for (auto it : elements) {
		if (it.second->isAnimated) {
			static_cast<Panel*>(it.second)->update();
		}
	}
}

void ElementManager::render()
{
	for (auto it = elements.begin(); it != elements.end(); it++) {
		it->second->render();

	}
}

void ElementManager::addElement(UIElement *e)
{
	addElement(e, "");
}

void ElementManager::addElement(UIElement * e, std::string s)
{
	elements.insert({s,e});
}

std::multimap<std::string, UIElement*>* ElementManager::getElements()
{
	return &elements;
}

ElementManager::ElementManager()
{
	this->white = al_map_rgb(255, 255, 255);
	EQ = al_create_event_queue();
	al_register_event_source(EQ, al_get_mouse_event_source());
}


ElementManager::~ElementManager()
{
	deleteElements();
}
