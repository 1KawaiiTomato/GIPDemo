#pragma once
#include "allegro5/allegro.h"
#include <iostream>
#include "tinyxml2.h"
#include <unordered_map>

class InputManager {
private:
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
		//KEEP AT END!
		AMOUNT_OF_BINDINGS
	};
	static std::vector<int>recordedKeystrokes;
	static bool recording;
	static tinyxml2::XMLDocument XMLDoc;
	static std::unordered_map<keyBindings, keyCodes>eventMap;
	static keyCodes getKeyCode(keyBindings kb);
	static void init();
	static void loadFromFile(std::string path);
	static void saveFile(std::string path);
	static void setDefaults();
	static void update();
};