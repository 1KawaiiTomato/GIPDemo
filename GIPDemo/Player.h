#pragma once
#include "World.h"
#include "VectorMath.h"
#include "Inventory.h"
#include "InputManager.h"

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
	void placeBlock(ALLEGRO_EVENT event, Camera *c, Inventory *inventory);
	void breakBlock(ALLEGRO_EVENT event, Camera *c, Inventory *inventory);
	Player();
	~Player();
};