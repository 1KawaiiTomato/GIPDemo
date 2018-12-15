#pragma once
#include "World.h"
#include "Player.h"
#include "ElementManager.h"
#include "Inventory.h"

class game
{
private:
	ElementManager UI;
	Camera cam;
	Player player;
	bool running;
	bool paused;
	ALLEGRO_COLOR BLACK;
	Textures textures;
	ALLEGRO_EVENT_QUEUE *EQ;
	ALLEGRO_DISPLAY *display;
	World world;
	Inventory inventory;
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