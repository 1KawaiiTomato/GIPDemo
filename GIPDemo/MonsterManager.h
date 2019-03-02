#pragma once
#include "allegro5/allegro.h"
#include "Camera.h"
#include "Mob.h"
#include "Textures.h"

class MonsterManager
{
private:

public:
	void update(); 
	void render();
	MonsterManager();
	~MonsterManager();
};

