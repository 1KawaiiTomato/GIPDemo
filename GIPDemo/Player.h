#pragma once
#include "allegro5/allegro.h"
#include "World.h"
#include "VectorMath.h"

class Player
{
private:
	ALLEGRO_BITMAP *texture;
	Vector movement;
	float speed;
public:
	World *world;
	float width, height;
	float x, y;
	void update();
	void render(Camera *c);
	Player();
	~Player();
};