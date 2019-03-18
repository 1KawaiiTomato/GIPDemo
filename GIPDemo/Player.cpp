#include "Player.h"
#include <iostream>


void Player::update()
{
	ALLEGRO_KEYBOARD_STATE KS;
	al_get_keyboard_state(&KS);
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_UP]) {
		this->movement.y -= 2;
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_LEFT]) {
		this->movement.x -= 1;
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_RIGHT]) {
		this->movement.x += 1;
	}
	if (!world->getTile(std::floor(x / 16), std::floor((y+16) / 16))->isSolid()) {
		this->movement.y += 1;
	}
	movement.normalize();
	this->x += this->movement.x*speed;
	this->y += this->movement.y*speed;
	this->movement = Vector(0, 0);
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

void Player::placeBlock(ALLEGRO_EVENT event, Camera *c, Inventory *inventory)
{
	int screenX = this->x * c->zoom + c->xOffset;
	int screenY = this->y * c->zoom + c->yOffset;
	if (inventory->holdingSomething() &&
		((std::pow(screenX - event.mouse.x, 2) + std::pow(screenY - event.mouse.y, 2)) <= 900 * 32 * c->zoom)) {
		int x = event.mouse.x;
		int y = event.mouse.y;
		std::pair<int, int> coordinates = c->screenToWorldCoordinates(x, y);
		x = coordinates.first / c->BLOCK_SIZE;
		y = coordinates.second / c->BLOCK_SIZE;
		if (world->getTile(x, y) == &world->terrainTypes["airBlock"]) {
			world->setTile(x, y, inventory->getHand());
			inventory->useHand();
		}
	}
}

void Player::breakBlock(ALLEGRO_EVENT event, Camera * c, Inventory *inventory)
{
	int screenX = this->x * c->zoom + c->xOffset;
	int screenY = this->y * c->zoom + c->yOffset;
	if ((std::pow(screenX - event.mouse.x, 2) + std::pow(screenY - event.mouse.y, 2)) <= 900*32*c->zoom) {
		int x = event.mouse.x;
		int y = event.mouse.y;
		std::pair<int, int> coordinates = c->screenToWorldCoordinates(x, y);
		x = coordinates.first / c->BLOCK_SIZE;
		y = coordinates.second / c->BLOCK_SIZE;

		if(world->getTile(x,y)->name != "airBlock")
			inventory->addObject(world->getTile(x,y)->name);
			world->setTile(x, y, &world->terrainTypes["airBlock"]);
	}
}

Player::Player()
{
	speed = 1;
	x = 200;
	y = 158;
	this->texture = al_load_bitmap("Images/player.png");
	this->width = al_get_bitmap_width(texture);
	this->height = al_get_bitmap_height(texture);
}


Player::~Player()
{
}
