#pragma once
#include "Textures.h"

class Terrain
{
private:
	ALLEGRO_BITMAP *texture;
public:
	ALLEGRO_BITMAP* getTexture();
	Terrain(ALLEGRO_BITMAP *texture);
	Terrain();
	~Terrain();
};

