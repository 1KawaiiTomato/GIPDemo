#pragma once
#include "allegro5/allegro.h"

class Camera
{
public:
	float zoom;
	float camX, camY;
	float xOffset, yOffset;
	void calculateOffset();
	Camera();
	~Camera();
};