#include "IAnimation.h"



IAnimation::IAnimation()
{
}


IAnimation::~IAnimation()
{
}

void IAnimation::setAnimation(std::vector<ALLEGRO_BITMAP*>* animation, int speed)
{
	setAnimationSpeed(speed);
	setAnimation(animation);
}

void IAnimation::setAnimation(std::vector<ALLEGRO_BITMAP*>* animation)
{
	this->animationLength = animation->size();
	this->animation = animation;
}

void IAnimation::setAnimationSpeed(int speed)
{
	ticksDivider = 60 / speed;
}

void IAnimation::updateAnimation()
{
	ticks++;
	if (ticks >= ticksDivider) {
		animationCount++;
		ticks = 0;
	}
	if (animationCount >= animationLength)
		animationCount = 0;
}
