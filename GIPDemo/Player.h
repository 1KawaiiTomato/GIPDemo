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
	void placeBlock(ALLEGRO_EVENT event, Camera *c);
	void breakBlock(ALLEGRO_EVENT event, Camera *c);
	Player();
	~Player();
};