#pragma once
#include <cmath>
#include <iostream>
#include "allegro5/allegro.h"

class Camera
{
public:
	const static int BLOCK_SIZE = 32;
	int dWidth, dHeight;
	float half_optimised_render_width, half_optimised_render_height;
	float zoom;
	float camX, camY;
	float xOffset, yOffset;
	std::pair<float, float> screenToWorldCoordinates(float x, float y);
	std::pair<float, float> worldToScreenCoordinates(float x, float y);
	void calculateOffset(float x, float y, float w, float h);
	void calculateOptimisedRenderSize();
	void update();
	void init();
	Camera();
	~Camera();
};