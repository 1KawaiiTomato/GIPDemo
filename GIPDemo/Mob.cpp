#include "Mob.h"



void Mob::render()
{
	al_draw_scaled_bitmap((*animation)[animationCount], 0, 0, 16, 16, ++x, y, 32, 32, 0);
}

void Mob::update()
{
	updateAnimation();
}

Mob::Mob()
{
	y = 395;
	x = std::rand() % 100;
	setAnimation(&Textures::getInstance().animations["frogIdle"], 6);
}

Mob::~Mob()
{
}
