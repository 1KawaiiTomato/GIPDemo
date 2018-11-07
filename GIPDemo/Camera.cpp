#include "Camera.h"



void Camera::calculateOffset(float x, float y, float w, float h)
{
	float width = al_get_display_width(al_get_current_display());
	float height = al_get_display_height(al_get_current_display());

	xOffset = width/2 - ((x+(w/2))*zoom);
	yOffset = height/2 - ((y+(h/2))*zoom);

	camX = x;
	camY = y;
}

void Camera::update()
{
	ALLEGRO_KEYBOARD_STATE KS;
	al_get_keyboard_state(&KS);
	if (al_key_down(&KS, ALLEGRO_KEY_U)) {
		this->zoom += 0.1;
	}
	if (al_key_down(&KS, ALLEGRO_KEY_D)) {
		this->zoom -= 0.1;
	}
	if (zoom < 0.1) {
		zoom = 0.1;
	}
}

Camera::Camera()
{
	zoom = 2.5;
	camX = xOffset = 0;
	camY = yOffset = 0;
}


Camera::~Camera()
{
}
