#pragma once
#define UPEVENT 0
#define DOWNEVENT 1

#include "allegro5/allegro.h"
#include <iostream>
#include "tinyxml2.h"
#include <unordered_map>

class InputManager {
private:
	static void saveDeltaTicks(unsigned int dt);
	InputManager();
public:
	enum keyBindings {
		LEFT_MOUSE,
		RIGHT_MOUSE,
		SCROLL,
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN,
		ZOOM_IN,
		ZOOM_OUT,
		TOGGLE_RECORD,
		//KEEP AT END!
		AMOUNT_OF_BINDINGS
	};
	//Recording
	static std::vector<std::pair<int, bool>> recordedKeystrokes;
	static std::vector<unsigned long long> recordedTimings;
	static unsigned long long deltaTicks;
	static bool recording;
	static bool replaying;

	//Persistent memory
	static tinyxml2::XMLDocument XMLDoc;

	//Keybindings
	static std::unordered_map<keyBindings, keyCodes>eventMap;
	static std::unordered_map<keyBindings, bool>isKeyDown;
	static keyCodes getKeyCode(keyBindings kb);
	static void loadFromFile(std::string path);
	static void saveFile(std::string path);
	static void setDefaults();

	//Static class initialization
	static void init();

	//Central event handler
	static ALLEGRO_EVENT_QUEUE *EQ;
	static void registerEventSources();
	static void handleEvents();
	static void update();
};