#pragma once
#include "World.h"
#include "Camera.h"

class game
{
private:
	Camera cam;
	bool running;
	ALLEGRO_COLOR BLACK;
	Textures textures;
	ALLEGRO_EVENT_QUEUE *EQ;
	ALLEGRO_DISPLAY *display;
	World world;
	void register_event_sources();
	void handleEvents();
public:
	void init();
	void startMain();
	void render();
	void update();
	game();
	~game();
};