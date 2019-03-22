#include "MonsterManager.h"


void MonsterManager::update()
{
	for (size_t i = 0; i < mobs.size(); i++) {
		mobs[i]->update();
	}
}

void MonsterManager::render(Camera *cam)
{
	for (size_t i = 0; i < mobs.size(); i++) {
		mobs[i]->render(cam);
	}
}

MonsterManager::MonsterManager()
{
	Textures::getInstance().loadTexturesFromAtlas("Images/monsters/bat.xml");
	Textures::getInstance().loadTexturesFromAtlas("Images/monsters/frog.xml");
	Textures::getInstance().loadTexturesFromAtlas("Images/monsters/ghost.xml");
	Textures::getInstance().loadTexturesFromAtlas("Images/monsters/skeleton.xml");
	mobs.push_back(new Frog());
	mobs.push_back(new Frog());
	mobs.push_back(new Skeleton());
	mobs.push_back(new Skeleton());
}


MonsterManager::~MonsterManager()
{
}