#pragma once
#include "allegro5/allegro.h"
#include <vector>

class IAnimation
{
protected:
	IAnimation();
	~IAnimation();
	void setAnimation(std::vector<ALLEGRO_BITMAP*>* animation, int speed);
	void setAnimation(std::vector<ALLEGRO_BITMAP*>* animation);
	void setAnimationSpeed(int speed);
	void updateAnimation();

	std::vector<ALLEGRO_BITMAP*>* animation;
	size_t animationLength = 0;
	int animationCount = 0;
	int ticksDivider = 10;
	int ticks = 0;
};