#pragma once
#include "Textures.h"
#include "IAnimation.h"
#include "allegro5/allegro.h"

class Mob : public IAnimation
{
private:
	float x, y;
	ALLEGRO_BITMAP *Texture;
	int bx, by;
public:
	virtual void render();
	virtual void update();
	Mob();
	~Mob();
};