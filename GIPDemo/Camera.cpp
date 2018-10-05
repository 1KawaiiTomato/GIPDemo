#include "Camera.h"



void Camera::calculateOffset()
{
	float width = al_get_display_width(al_get_current_display());
	float height = al_get_display_height(al_get_current_display());

	xOffset = (width - camX) / 2;
	yOffset = (height - camY) / 2;
}

void Camera::calculateOffset(float x, float y, float w, float h)
{
	float width = al_get_display_width(al_get_current_display());
	float height = al_get_display_height(al_get_current_display());

	xOffset = width/2 - ((x+(w/2))*zoom);
	yOffset = height/2 - ((y+(h/2))*zoom);

	camX = x;
	camY = y;
}

Camera::Camera()
{
	zoom = 0;
	camX = xOffset;
	camY = yOffset;
}


Camera::~Camera()
{
}
