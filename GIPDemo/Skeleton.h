#pragma once
#include "Mob.h"
class Skeleton :
	public Mob
{
private:
	int direction; //-1 = left, 1 = right;
public:
	void render(Camera *cam) override;
	void update() override;
	Skeleton();
	~Skeleton();
};

