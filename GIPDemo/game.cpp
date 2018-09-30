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
	world.render();
	al_flip_display();
}

void game::update()
{
	world.update();
}

game::game()
{
}


game::~game()
{
}
