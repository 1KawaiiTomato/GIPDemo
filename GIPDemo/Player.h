#pragma once
#include "World.h"
#include "VectorMath.h"
#include "Inventory.h"
#include "InputManager.h"
#if _DEBUG
#include "allegro5/allegro_primitives.h"
#endif

class Player
	: public IAnimation
{
private:
	class heartUI {
	public:
		ALLEGRO_BITMAP *heartTexture;
		const int maxLifes = 6;
		int x = 0;
		int lifes = maxLifes;
		void render();
		heartUI();
	};
	ALLEGRO_BITMAP *texture;
	Vector movement;
	float speed;
	float fallSpeed;
	int flag = 0;
	bool onGround;
public:
	heartUI *hearts;
	World *world;
	float width, height;
	float x, y;
	void init();
	void update();
	void updatePhysics();
	void render(Camera *c);
	void placeBlock(ALLEGRO_EVENT event, Camera *c, Inventory *inventory);
	void breakBlock(ALLEGRO_EVENT event, Camera *c, Inventory *inventory);
	Player();
	~Player();
};