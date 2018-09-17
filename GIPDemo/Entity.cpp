#include "Entity.h"



Entity::Entity(float x, float y, float w, float h, bool solid)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->isSolid = solid;
}

Entity::Entity()
{
}


Entity::~Entity()
{
}
