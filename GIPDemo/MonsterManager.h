#pragma once
#include "allegro5/allegro.h"
#include "Camera.h"
#include "Textures.h"
#include "Frog.h"


class MonsterManager
{
private:
	std::vector<Mob*> mobs;
public:
	void update(); 
	void render(Camera *cam);
	MonsterManager();
	~MonsterManager();
};

