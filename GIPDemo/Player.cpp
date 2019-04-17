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
	if (idle)
		setAnimation("adventurerIdle", 3);
	else
		setAnimationSpeed(8);
	updatePhysics();
	updateAnimation();
}

void Player::updatePhysics()
{
	float x = this->x;
	float y = this->y;
	movement.y++;
	movement.normalize();

	//X-axis
	x += this->movement.x*speed;
	if (movement.x > 0) {
		if (world->getTile((x / 16 + 0.9), (y / 16))->isSolid() ||
			world->getTile((x / 16 + 0.9), (y / 16 + 0.9))->isSolid()) {
			std::cout << "x: " << x << std::endl;
			x = (int)this->x + 0.1;
			setAnimation("adventurerIdle");
			std::cout << "nx: " << x << std::endl;
			std::cout << "--------------------------------" << std::endl;
		}
	}
	else {
		if (world->getTile((x / 16 + 0.6), (y / 16))->isSolid() ||
			world->getTile((x / 16 + 0.6), (y / 16 + 0.9))->isSolid()) {
			x = ((int)this->x) + 0.6;
			setAnimation("adventurerIdle");
		}
	}
	//Y-axis
	y += this->movement.y*speed;
	if (movement.y >= 0) {
		if (world->getTile(x / 16 + 0.6, y / 16 + 1)->isSolid() ||
			world->getTile(x / 16 + 0.9, y / 16 + 1)->isSolid()) {
			y = (int)y;
			movement.y = -1;
		}
	}
	else {
		if (world->getTile(x / 16 + 0.6, y / 16)->isSolid() ||
			world->getTile(x / 16 + 0.9, y / 16)->isSolid()) {
			y = (int)y+1;
		}
	}
	this->movement = Vector(0, movement.y);
	this->x = x;
	this->y = y;
}

void Player::render(Camera *c)
{
	al_draw_scaled_bitmap(
		(*animation)[animationCount]
		, 0, 0, width, height
		, x*c->zoom + c->xOffset
		, y*c->zoom + c->yOffset
		, width * c->zoom, height * c->zoom, flag);
#if _DEBUG
	std::pair<int, int> coords = { x*c->zoom + c->xOffset, y*c->zoom + c->yOffset };
	al_draw_rectangle(coords.first, coords.second,
		coords.first + this->width*c->zoom, coords.second + this->height*c->zoom,
		al_map_rgb(10, 10, 10), 0);
#endif
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
