#include "IAnimation.h"



IAnimation::IAnimation()
{
}


IAnimation::~IAnimation()
{
}

void IAnimation::setAnimation(std::string animationName, int speed)
{
	setAnimationSpeed(speed);
	setAnimation(animationName);
}

void IAnimation::setAnimation(std::string animationName)
{
	this->animation = &Textures::getInstance().animations[animationName];
	this->animationLength = animation->size();
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
