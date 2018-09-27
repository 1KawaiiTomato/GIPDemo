#include "game.h"



void game::init()
{
	display = al_create_display(400, 400);
	textures.loadTexturesFromAtlas("Images/blueSheet.xml");
}

void game::startMain()
{
	while (true) {
		this->update();
		this->render();
	}
}

void game::render()
{
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(textures.textures["blue_button04.png"], 0, 0, 0);
	al_flip_display();
}

void game::update()
{
}

game::game()
{
}


game::~game()
{
}
