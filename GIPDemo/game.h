#pragma once
#include "Textures.h"

class game
{
private:
	ALLEGRO_DISPLAY *display;
public:
	void init();
	void startMain();
	void render();
	void update();
	game();
	~game();
};