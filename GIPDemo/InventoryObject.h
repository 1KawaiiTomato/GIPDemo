#pragma once
#include "allegro5/allegro.h"
#include "World.h"

class InventoryObject
{
public:
	Terrain* terrainPointer;
	ALLEGRO_BITMAP *texture;
	InventoryObject(ALLEGRO_BITMAP *texture);
	InventoryObject(ALLEGRO_BITMAP *texture, Terrain* terrain);
	InventoryObject();
	~InventoryObject();
};

