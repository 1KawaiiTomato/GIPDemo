#pragma once
#include "IState.h"
#include "Player.h"
#include "CollisionComponent.h"
#include "CollisionComponent.cpp"

class Player;

class IdleState
	: public IState
{
public:
	void updatePhysics(Player &player);
	void update(Player &player);
	void render(Player &player);
	IdleState();
	~IdleState();
};

