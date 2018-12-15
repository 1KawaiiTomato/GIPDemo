#pragma once
#include "allegro5/allegro.h"

class InventoryObject
{
public:
	ALLEGRO_BITMAP *texture;
	InventoryObject(ALLEGRO_BITMAP *texture);
	InventoryObject();
	~InventoryObject();
};

