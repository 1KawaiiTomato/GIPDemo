#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <iostream>
#include "game.h"
#include "InputManager.h"

int main()
{
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_mouse();
	al_install_joystick();
	
	InputManager::init();

	Game g;
	g.init();
	g.startMain();

	InputManager::saveFile("Data/keyBindings.xml");
	return 0;
}