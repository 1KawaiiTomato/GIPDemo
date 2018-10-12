#include "Player.h"
#include <iostream>


void Player::update()
{
}

void Player::render(Camera *c)
{
	/*al_draw_scaled_bitmap(texture
		, 0, 0, width, height
		,(((x ) - c->camX) * c->zoom) + c->xOffset
		, ((y ) - c->camY)*c->zoom + c->yOffset
		, width * c->zoom, height * c->zoom, 0);*/
	/*al_draw_scaled_bitmap(texture
		, 0, 0, width, height
		, x + c->xOffset
		, y + c->yOffset
		, width * c->zoom, height * c->zoom, 0);*/
	al_draw_scaled_bitmap(texture
		, 0, 0, width, height
		, x*c->zoom + c->xOffset
		, y*c->zoom + c->yOffset
		, width * c->zoom, height * c->zoom, 0);
	//al_draw_bitmap(texture, x + c->xOffset, y + c->yOffset, 0);
}

Player::Player()
{
	x = 0;
	y = 0;
	this->texture = al_load_bitmap("Images/player.png");
	this->width = al_get_bitmap_width(texture);
	this->height = al_get_bitmap_height(texture);
}


Player::~Player()
{
}
