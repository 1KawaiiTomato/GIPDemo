#pragma once
#include "Entity.h"

class Placeable : public Entity
{
public:
	ALLEGRO_BITMAP *texture;
	int power;
	Placeable(float x, float y, float w, float h, bool solid);
	Placeable();
	~Placeable();
};