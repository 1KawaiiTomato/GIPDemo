#include "Player.h"
#include <iostream>


void Player::update()
{
	bool idle = true;
	ALLEGRO_KEYBOARD_STATE KS;
	al_get_keyboard_state(&KS);
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_UP]) {
		this->movement.y -= 2;
		setAnimation("adventurerJump"); idle = false; 
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_LEFT]) {
		this->movement.x -= 1;
		setAnimation("adventurerRun"); idle = false; flag = ALLEGRO_FLIP_HORIZONTAL;
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_RIGHT]) {
		this->movement.x += 1;
		setAnimation("adventurerRun"); idle = false; flag = 0;
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_DOWN]) {
		setAnimation("adventurerCrouch"); idle = false;
	}
	if (!world->getTile(std::floor(x / 16), std::floor((y+16) / 16))->isSolid()) {
		this->movement.y += 1;
	}
	if (idle)
		setAnimation("adventurerIdle", 3);
	else
		setAnimationSpeed(8);
	movement.normalize();
	this->x += this->movement.x*speed;
	this->y += this->movement.y*speed;
	this->movement = Vector(0, 0);
	updateAnimation();
}

void Player::render(Camera *c)
{
	al_draw_scaled_bitmap(
		(*animation)[animationCount]
		, 0, 0, width, height
		, x*c->zoom + c->xOffset
		, y*c->zoom + c->yOffset
		, width * c->zoom, height * c->zoom, flag);
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
	Textures::getInstance().loadTexturesFromAtlas("Images/player/adventurer.xml");
	speed = 1;
	x = 198;
	y = 158;
	this->width = 50;//al_get_bitmap_width(texture);
	this->height = 37;// al_get_bitmap_height(texture);
	setAnimation("adventurerIdle", 8);
}


Player::~Player()
{
}
