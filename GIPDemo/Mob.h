#pragma once
#include "Textures.h"
#include "IAnimation.h"
#include "Camera.h"
#include "allegro5/allegro.h"

class Mob : public IAnimation
{
protected:
	float x, y;
	int destinationWidth, destinationHeight;
	int flag;
	int idleFrame;
	bool idle;
public:
	virtual void render(Camera *cam);
	virtual void update();
	Mob();
	~Mob();
};