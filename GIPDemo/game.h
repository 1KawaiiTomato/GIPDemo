#pragma once
#include "World.h"
#include "Player.h"
#include "ElementManager.h"
#include "Inventory.h"
#include "allegro5/allegro_primitives.h"

class Game
{
private:
	ElementManager UI;
	Camera cam;
	Player player;
	bool running;
	bool paused;
	ALLEGRO_COLOR BLACK;
	//Textures textures;
	ALLEGRO_TIMER *timer;
	ALLEGRO_EVENT_QUEUE *timerQueue;
	ALLEGRO_EVENT_QUEUE *EQ;
	ALLEGRO_DISPLAY *display;
	Inventory inventory;
	void register_event_sources();
	void handleEvents();
public:
	World world;
	void init();
	void startMain();
	void render();
	void update();
	void fade_in(ALLEGRO_BITMAP *bmp);
	void fade_out();
	Game();
	~Game();
};