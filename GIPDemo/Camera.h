#pragma once
#include "allegro5/allegro.h"

class Camera
{
public:
	float zoom;
	float camX, camY;
	float xOffset, yOffset;
	void calculateOffset();
	void calculateOffset(float x, float y, float w, float h);
	Camera();
	~Camera();
};