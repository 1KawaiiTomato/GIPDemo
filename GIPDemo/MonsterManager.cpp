#include "MonsterManager.h"


void MonsterManager::update()
{
}

void MonsterManager::render()
{
}

MonsterManager::MonsterManager()
{
	Textures::getInstance().loadTexturesFromAtlas("Images/monsters/bat.xml");
}


MonsterManager::~MonsterManager()
{
}