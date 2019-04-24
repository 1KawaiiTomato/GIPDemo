#include "IdleState.h"


void IdleState::updatePhysics(Player &player)
{
	CollisionComponent<Player>::updatePhysics(&player);
	/*
	float x = player.x;
	float y = player.y;
	player.movement.y++;
	player.movement.normalize();

	//X-axis
	x += player.movement.x*player.speed;
	if (player.movement.x > 0) {
		if (player.world->getTile((x / 16 + 0.85), (y / 16))->isSolid() ||
			player.world->getTile((x / 16 + 0.85), (y / 16 + 0.9))->isSolid()) {
			x = std::ceil(player.x) - 0.15;
			player.setAnimation("adventurerIdle");
		}
	}
	else {
		if (player.world->getTile((x / 16 + 0.6), (y / 16))->isSolid() ||
			player.world->getTile((x / 16 + 0.6), (y / 16 + 0.9))->isSolid()) {
			x = ((int)player.x) + 0.6;
			player.setAnimation("adventurerIdle");
		}
	}
	//Y-axis
	y += player.movement.y*player.speed;
	if (player.movement.y >= 0) {
		if (player.world->getTile(x / 16 + 0.6, y / 16 + 1)->isSolid() ||
			player.world->getTile(x / 16 + 0.7, y / 16 + 1)->isSolid()) {
			y = (int)y;
			player.movement.y = -1;
		}
	}
	else {
		if (player.world->getTile(x / 16 + 0.6, y / 16)->isSolid() ||
			player.world->getTile(x / 16 + 0.7, y / 16)->isSolid()) {
			y = (int)y + 1;
		}
	}
	player.movement = Vector(0, player.movement.y);
	player.x = x;
	player.y = y;
	*/
}

void IdleState::update(Player &player)
{
	bool idle = true;
	ALLEGRO_KEYBOARD_STATE KS;
	al_get_keyboard_state(&KS);
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_UP]) {
		player.movement.y -= 2;
		player.setAnimation("adventurerJump"); idle = false;
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_LEFT]) {
		player.movement.x -= 1;
		player.setAnimation("adventurerRun"); idle = false; player.flag = ALLEGRO_FLIP_HORIZONTAL;
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_RIGHT]) {
		player.movement.x += 1;
		player.setAnimation("adventurerRun"); idle = false; player.flag = 0;
	}
	if (InputManager::isKeyDown[InputManager::keyBindings::MOVE_DOWN]) {
		player.setAnimation("adventurerCrouch"); idle = false;
	}
	if (idle)
		player.setAnimation("adventurerIdle", 3);
	else
		player.setAnimationSpeed(8);
	updatePhysics(player);
	player.updateAnimation();
}

void IdleState::render(Player &player)
{
}

IdleState::IdleState()
{
}


IdleState::~IdleState()
{
}
