#include "game.h"



void game::register_event_sources()
{
	try
	{
		al_register_event_source(EQ, al_get_display_event_source(al_get_current_display()));
		al_register_event_source(EQ, al_get_keyboard_event_source());
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
		case ALLEGRO_EVENT_KEY_DOWN:
			if (E.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				paused = !paused;
			break;
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
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	display = al_create_display(960, 540);
	EQ = al_create_event_queue();
	this->register_event_sources();
	BLACK = al_map_rgb(0,0,0);
	textures.loadTexturesFromAtlas("Images/spritesheet.xml");
	world = World(&textures, "Data/terrain.xml");
	world.init();
	inventory.init(&textures);
	running = true;
	paused = false;
	player.world = &world;
	UIElement *e = new Panel("Images/frame.png", 0, 0);
	UI.addElement(e);
	e = new Panel("Images/frame.png", 0.04, 0);
	UI.addElement(e);
	e = new Panel("Images/frame.png", 0.08, 0);
	UI.addElement(e);
	e = new Panel("Images/frame.png", 0.12, 0);
	UI.addElement(e);
}

void game::startMain()
{
	while (running) {
		this->handleEvents();
		UI.update();
		if (!paused) {
			this->update();
		}
		else {
			inventory.update();
		}
		this->render();
	}
}

void game::render()
{
	al_clear_to_color(BLACK);
	world.render(&cam);
	player.render(&cam);
	//UI.render();
	if (paused) {
		inventory.draw();
	}
	else {
		inventory.drawHotbar();
	}
	al_flip_display();
}

void game::update()
{
	cam.update();
	cam.calculateOffset(player.x, player.y, player.width, player.height);
	world.update();
	player.update();
}

game::game()
{
}


game::~game()
{
}
