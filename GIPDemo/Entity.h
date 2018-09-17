#pragma once
#include "allegro5/allegro.h"
class Entity
{
public:
	float x, y, w, h;
	bool isSolid;
	Entity(float x, float y, float w, float h, bool solid);
	Entity();
	~Entity();
};

