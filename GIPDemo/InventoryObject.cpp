#include "InventoryObject.h"



InventoryObject::InventoryObject(ALLEGRO_BITMAP *texture) : texture(texture)
{
}

InventoryObject::InventoryObject(ALLEGRO_BITMAP * texture, Terrain * terrain) : texture(texture),terrainPointer(terrain)
{
}

InventoryObject::InventoryObject()
{
}


InventoryObject::~InventoryObject()
{
}
