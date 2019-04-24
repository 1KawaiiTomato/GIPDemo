#pragma once

class Player;

class IState
{
public:
	virtual void update(Player &player) = 0;
	virtual void render(Player &player) = 0;
};