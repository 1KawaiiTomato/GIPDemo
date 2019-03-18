#include "Mob.h"



void Mob::render(Camera *cam)
{
	std::pair<int, int> coords = cam->worldToScreenCoordinates(x, y);

	if (idle)
		al_draw_scaled_bitmap((*animation)[0], 0, 0, 16, 16,
			coords.first, coords.second, 16 * cam->zoom, 16 * cam->zoom, flag);
	else
		al_draw_scaled_bitmap((*animation)[animationCount], 0, 0, 16, 16,
		coords.first, coords.second, 16 * cam->zoom, 16 * cam->zoom, flag);
}

void Mob::update()
{
	updateAnimation();
}

Mob::Mob()
{
	x = 200;
	y = 336;
}

Mob::~Mob()
{
}
