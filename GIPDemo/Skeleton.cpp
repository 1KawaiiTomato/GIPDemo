#include "Skeleton.h"


void Skeleton::render(Camera *cam)
{

	if (direction == -1)
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else
		flag = 0;

	Mob::render(cam);
}

void Skeleton::update()
{
	Mob::update();
	if (std::rand() % 50 == 0)
		direction = rand() % 3 - 1;
	if (!direction)
		idle = true;
	else
		idle = false;
	x += direction;
}

Skeleton::Skeleton()
{
	idleFrame = 1;
	direction = 1;
	setAnimation("skeletonIdle");
}


Skeleton::~Skeleton()
{
}
