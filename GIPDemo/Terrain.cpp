#include "Terrain.h"



ALLEGRO_BITMAP * Terrain::getTexture()
{
	return texture;
}

Terrain::Terrain(ALLEGRO_BITMAP * tex) : texture(tex)
{
}

Terrain::Terrain()
{
}

Terrain::~Terrain()
{
}
