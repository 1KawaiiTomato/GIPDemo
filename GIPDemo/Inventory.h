#pragma once
#include "allegro5/allegro_font.h"
#include "InventoryObject.h"
#include <unordered_map>
#include "tinyxml2.h"
#include <iostream>
#include "Textures.h"

class Inventory
{
private:
	int selectedFrame;
	ALLEGRO_BITMAP *selectionFrame;
	ALLEGRO_BITMAP *frame;
	ALLEGRO_FONT *font;
	bool dragging = false;
	const static int SCALE = 60;
	const static int XOFFSET = 6;
	const static int YOFFSET = 6;
	const static int XOFFSET_OBJ = 6;
	const static int YOFFSET_OBJ = 6;
	const static int FRAMES_WIDTH = 6;
	const static int FRAMES_HEIGHT = 4;
	std::unordered_map<std::string, InventoryObject> inventoryObjects;
	std::pair<InventoryObject *, int> inventoryArray[FRAMES_WIDTH][FRAMES_HEIGHT];
	std::pair<InventoryObject *, int> selectedObj;
	ALLEGRO_EVENT_QUEUE *PausedEvents_Queue;
	ALLEGRO_EVENT_QUEUE *UnpausedEvents_Queue;
public:
	bool holdingSomething();
	Terrain *getHand();
	void DragItem(float x, float y, std::string mode);
	void loadTypes(std::string path, World *world);
	void init(World *world);
	void addObject(std::string objectName);
	void selectFrame(int dIndex);
	void handleUnpausedEvents();
	void handlePausedEvents();
	void setPaused(bool b);
	void drawHotbar();
	void useHand();
	void draw();
	void update();
	Inventory();
	~Inventory();
};

