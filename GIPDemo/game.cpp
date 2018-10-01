#include "game.h"



void game::register_event_sources()
{
	try
	{
		al_register_event_source(EQ, al_get_display_event_source(al_get_current_display()));
	}
	catch (...)
	{
		std::cout << "error registering event sources." << std::endl;
	}
}

void game::handleEvents()
{
	ALLEGRO_EVENT E;
	while (al_get_next_event(EQ, &E)) {
		switch (E.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			running = false;
			break;
		default:
			break;
		}
	}
}

void game::init()
{
	display = al_create_display(800, 600);
	EQ = al_create_event_queue();
	this->register_event_sources();
	BLACK = al_map_rgb(0,0,0);
	textures.loadTexturesFromAtlas("Images/blueSheet.xml");
	world = World(&textures);
	world.init();
	running = true;
}

void game::startMain()
{
	while (running) {
		this->handleEvents();
		this->update();
		this->render();
	}
}

void game::render()
{
	al_clear_to_color(BLACK);
	world.render(&cam);
	al_flip_display();
}

void game::update()
{
	cam.calculateOffset();
	ALLEGRO_KEYBOARD_STATE ks;
	al_get_keyboard_state(&ks);
	if (al_key_down(&ks, ALLEGRO_KEY_LEFT)) {
		this->cam.camX -= 0.5;
		std::cout << "left \n";
	}if (al_key_down(&ks, ALLEGRO_KEY_RIGHT)) {
		this->cam.camX += 0.5;
		std::cout << "right \n";
	}if (al_key_down(&ks, ALLEGRO_KEY_UP)) {
		this->cam.camY -= 0.5;
		std::cout << "up \n";
	}if (al_key_down(&ks, ALLEGRO_KEY_DOWN)) {
		this->cam.camY += 0.5;
		std::cout << "down \n";
	}if (al_key_down(&ks, ALLEGRO_KEY_U)) {
		this->cam.zoom += 0.1;
		std::cout << "U \n";
	}if (al_key_down(&ks, ALLEGRO_KEY_D)) {
		this->cam.zoom -= 0.1;
		std::cout << "D \n";
	}
	world.update();
}

game::game()
{
}


game::~game()
{
}
