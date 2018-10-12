#pragma once
#include "allegro5/allegro.h"
#include "Camera.h"

class Player
{
private:
	ALLEGRO_BITMAP *texture;
public:
	float width, height;
	float x, y;
	void update();
	void render(Camera *c);
	Player();
	~Player();
};