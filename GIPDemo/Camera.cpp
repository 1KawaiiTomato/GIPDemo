#include "Camera.h"



std::pair<float, float> Camera::screenToWorldCoordinates(float x, float y)
{
	x = ((x - xOffset) / zoom + camX) / BLOCK_SIZE;
	y = ((y - yOffset) / zoom + camY) / BLOCK_SIZE;
	return { x,y };
}

std::pair<float, float> Camera::worldToScreenCoordinates(float x, float y)
{
	x = (x*BLOCK_SIZE - camX) * zoom + xOffset;
	y = (y*BLOCK_SIZE - camY) * zoom + yOffset;
	return { x,y };
}

void Camera::calculateOffset(float x, float y, float w, float h)
{
	xOffset = dWidth/2 - ((x+(w/2))*zoom);
	yOffset = dHeight/2 - ((y+(h/2))*zoom);

	camX = x;
	camY = y;
}

void Camera::calculateOptimisedRenderSize()
{
	half_optimised_render_width = std::ceil(dWidth / (zoom * BLOCK_SIZE))/2 + 1;
	half_optimised_render_height = std::ceil(dHeight / (zoom * BLOCK_SIZE))/2 + 1;

	std::cout << "hoWidth: " << half_optimised_render_width << "\nhoHeight: " << half_optimised_render_height << std::endl << std::endl;
}

void Camera::update()
{
	ALLEGRO_KEYBOARD_STATE KS;
	al_get_keyboard_state(&KS);
	if (al_key_down(&KS, InputManager::eventMap[InputManager::keyBindings::ZOOM_IN])) {
		InputManager::getKeyCode(InputManager::keyBindings::ZOOM_IN);
		this->zoom += 0.1;
	}
	if (al_key_down(&KS, InputManager::eventMap[InputManager::keyBindings::ZOOM_OUT])) {
		InputManager::getKeyCode(InputManager::keyBindings::ZOOM_OUT);
		this->zoom -= 0.1;
	}
	if (zoom < 0.1) {
		zoom = 0.1;
	}
}

void Camera::init()
{
	dWidth = al_get_display_width(al_get_current_display());
	dHeight = al_get_display_height(al_get_current_display());

	calculateOptimisedRenderSize();
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
