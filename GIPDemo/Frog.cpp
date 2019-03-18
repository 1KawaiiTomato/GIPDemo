#include "Frog.h"



void Frog::render(Camera *cam)
{

	if (direction == -1)
		flag = ALLEGRO_FLIP_HORIZONTAL;
	else
		flag = 0;

	Mob::render(cam);
}

void Frog::update()
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

Frog::Frog()
{
	direction = 1;
	setAnimation("frogIdle");
}


Frog::~Frog()
{
}
