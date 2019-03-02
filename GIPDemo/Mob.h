#pragma once
#include "MonsterManager.h"

class Mob
{
private:
	float x, y;
	ALLEGRO_BITMAP *Texture;
public:
	virtual void render();
	virtual void update();
	Mob();
	~Mob();
};

