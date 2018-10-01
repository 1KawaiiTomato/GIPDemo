#include "Camera.h"



void Camera::calculateOffset()
{
	float width = al_get_display_width(al_get_current_display());
	float height = al_get_display_height(al_get_current_display());

	xOffset = (width - camX) / 2;
	yOffset = (height - camY) / 2;
}

Camera::Camera()
{
	zoom = 3;
}


Camera::~Camera()
{
}
