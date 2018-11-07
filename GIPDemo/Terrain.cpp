#include "Terrain.h"



ALLEGRO_BITMAP * Terrain::getTexture()
{
	return texture;
}

int Terrain::getPower()
{
	return power;
}

bool Terrain::isSolid()
{
	return solid;
}

Terrain::Terrain(ALLEGRO_BITMAP * tex, int power, bool solid) : texture(tex), power(power), solid(solid)
{
}

Terrain::Terrain()
{
}

Terrain::~Terrain()
{
}
