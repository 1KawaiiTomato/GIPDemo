#include "CollisionComponent.h"



template<typename T>
void CollisionComponent<T>::updatePhysics(T *t)
{
	float x = t->x;
	float y = t->y;
	t->movement.y++;
	t->movement.normalize();

	//X-axis
	x += t->movement.x*t->speed;
	if (t->movement.x > 0) {
		if (t->world->getTile((x / 16 + 0.85), (y / 16))->isSolid() ||
			t->world->getTile((x / 16 + 0.85), (y / 16 + 0.9))->isSolid()) {
			x = std::ceil(t->x) - 0.15;
			t->setAnimation("adventurerIdle");
		}
	}
	else {
		if (t->world->getTile((x / 16 + 0.6), (y / 16))->isSolid() ||
			t->world->getTile((x / 16 + 0.6), (y / 16 + 0.9))->isSolid()) {
			x = ((int)t->x) + 0.6;
			t->setAnimation("adventurerIdle");
		}
	}
	//Y-axis
	y += t->movement.y*t->speed;
	if (t->movement.y >= 0) {
		if (t->world->getTile(x / 16 + 0.6, y / 16 + 1)->isSolid() ||
			t->world->getTile(x / 16 + 0.7, y / 16 + 1)->isSolid()) {
			y = (int)y;
			t->movement.y = -1;
		}
	}
	else {
		if (t->world->getTile(x / 16 + 0.6, y / 16)->isSolid() ||
			t->world->getTile(x / 16 + 0.7, y / 16)->isSolid()) {
			y = (int)y + 1;
		}
	}
	t->movement = Vector(0, t->movement.y);
	t->x = x;
	t->y = y;
}