#include "game.h"



void Game::register_event_sources()
{
	try
	{
		al_register_event_source(EQ, al_get_display_event_source(al_get_current_display()));
		al_register_event_source(EQ, al_get_keyboard_event_source());
		al_register_event_source(EQ, al_get_mouse_event_source());
		al_register_event_source(timerQueue, al_get_timer_event_source(timer));
	}
	catch (...)
	{
		std::cout << "error registering event sources." << std::endl;
	}
}

void Game::handleEvents()
{
	ALLEGRO_EVENT E;
	while (al_get_next_event(EQ, &E)) {
		switch (E.type)
		{
		case ALLEGRO_EVENT_KEY_DOWN:
			if (E.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				paused = !paused;
				inventory.setPaused(!paused);
			break;
		case ALLEGRO_EVENT_KEY_UP:
			if (E.keyboard.keycode == InputManager::keyMap[InputManager::keyBindings::ZOOM_IN]
				|| E.keyboard.keycode == InputManager::keyMap[InputManager::keyBindings::ZOOM_OUT])
				cam.calculateOptimisedRenderSize();
			break;
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			running = false;
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			if (!paused) {
				if (E.mouse.button == 1)
					player.breakBlock(E, &cam, &inventory);
				if (E.mouse.button == 2)
					player.placeBlock(E, &cam, &inventory);
			}
			break;
		default:
			break;
		}
	}
}

void Game::init()
{
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	display = al_create_display(960, 540);
	EQ = al_create_event_queue();
	timerQueue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);
	this->register_event_sources();
	BLACK = al_map_rgb(0,0,0);
	textures.loadTexturesFromAtlas("Images/spritesheet.xml");
	world = World(&textures, "Data/terrain.xml");
	world.init();
	cam.init();
	inventory.init(&textures, &world);
	running = true;
	paused = false;
	player.world = &world;
	#if !_DEBUG
		fade_in(al_load_bitmap("Images/startScreen.png"));
		fade_out();
	#endif
}

void Game::startMain()
{
	al_start_timer(timer);
	while (running) {
		ALLEGRO_EVENT E;
		al_wait_for_event(timerQueue, &E);
	
		this->handleEvents();
		//UI.update();
		if (!paused) { this->update(); }
		inventory.update();
		if(al_event_queue_is_empty(timerQueue))
			this->render();
	}
}

void Game::render()
{
	al_clear_to_color(al_map_rgb(91, 76, 255));
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

void Game::update()
{
	cam.update();
	cam.calculateOffset(player.x, player.y, player.width, player.height);
	InputManager::update();
	world.update();
	player.update();
}

Game::Game()
{
}


Game::~Game()
{
}

void Game::fade_in(ALLEGRO_BITMAP *bmp)
{
	int width = al_get_display_width(display);
	int height = al_get_display_height(display);
	
	for (float alpha = 1.0; alpha > 0.0; alpha -= 0.001) {
		al_draw_bitmap(bmp, (width - 480) / 2, (height - 480) / 2, 0);
		al_draw_filled_rectangle(0, 0, width, height, al_map_rgba_f(1 * alpha, 1 * alpha, 1 * alpha, alpha));
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
}

void Game::fade_out()
{
	int width = al_get_display_width(display);
	int height = al_get_display_height(display);

	this->update();
	
	for (float alpha = 1.0; alpha > 0.0; alpha -= 0.004) {
		al_clear_to_color(al_map_rgb(91, 76, 255));
		world.render(&cam);
		player.render(&cam);
		al_draw_filled_rectangle(0, 0, width, height, al_map_rgba_f(0, 0, 0, alpha));
		al_flip_display();
	}
}
