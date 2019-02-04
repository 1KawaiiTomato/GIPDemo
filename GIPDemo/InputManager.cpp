#include "InputManager.h"

//Keybindings
std::unordered_map<InputManager::keyBindings, keyCodes>InputManager::eventMap;
std::unordered_map<InputManager::keyBindings, bool>InputManager::isKeyDown;

//Persistent memory
tinyxml2::XMLDocument InputManager::XMLDoc;

//Recording
unsigned long long InputManager::deltaTicks;
bool InputManager::recording;
bool InputManager::replaying;
std::vector<std::pair<int, bool>>InputManager::recordedKeystrokes;
std::vector<unsigned long long>InputManager::recordedTimings;

//Central event handler
ALLEGRO_EVENT_QUEUE *InputManager::EQ;

void InputManager::saveDeltaTicks(unsigned int dt)
{
	InputManager::recordedTimings.push_back(dt);
	InputManager::deltaTicks = 0;
}

keyCodes InputManager::getKeyCode(keyBindings kb)
{
	if (recording) {
		//recordedKeystrokes.push_back(kb);
	}
	return InputManager::eventMap[kb];
}

void InputManager::init() {
	InputManager::eventMap = std::unordered_map<keyBindings, keyCodes>();
	setDefaults();
	recording = true;
	deltaTicks = 0;
	loadFromFile("Data/keyBindings.xml");

	EQ = al_create_event_queue();
	registerEventSources();
}

void InputManager::loadFromFile(std::string path)
{
	tinyxml2::XMLError eResult = InputManager::XMLDoc.LoadFile(path.c_str());
	if (eResult != tinyxml2::XML_SUCCESS) { std::cout << "texture keyBindings xml failed to load."; };

	tinyxml2::XMLElement *Root = InputManager::XMLDoc.FirstChildElement("Bindings");

	for (tinyxml2::XMLElement* child = Root->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		int kb = child->IntAttribute("keyBinding");
		int kc = child->IntAttribute("keyCode");
		keyBindings kbe = static_cast<keyBindings>(kb);
		keyCodes kce = static_cast<keyCodes>(kc);
		InputManager::eventMap[kbe] = kce;
	}
}

void InputManager::saveFile(std::string path)
{
	int i = 0;
	tinyxml2::XMLElement *Root = InputManager::XMLDoc.FirstChildElement("Bindings");
	for (tinyxml2::XMLElement* child = Root->FirstChildElement(); child != NULL; child = child->NextSiblingElement()) {
		keyBindings kb = static_cast<keyBindings>(i);
		child->SetAttribute("keyBinding", kb);
		child->SetAttribute("keyCode", InputManager::eventMap[kb]);
		i++;
	}
	if (i < keyBindings::AMOUNT_OF_BINDINGS) {
		for (int j = 0; j < (keyBindings::AMOUNT_OF_BINDINGS - i); i++) {
			tinyxml2::XMLElement *element = XMLDoc.NewElement("Binding");
			Root->InsertEndChild(element);
		}
		//Re-save in case any settings were missed
		saveFile(path);
	}
	InputManager::XMLDoc.SaveFile(path.c_str());
}

void InputManager::setDefaults()
{
	InputManager::eventMap[MOVE_LEFT] = keyCodes::ALLEGRO_KEY_Q;
	InputManager::eventMap[MOVE_RIGHT] = keyCodes::ALLEGRO_KEY_D;
	InputManager::eventMap[MOVE_UP] = keyCodes::ALLEGRO_KEY_Z;
	InputManager::eventMap[MOVE_DOWN] = keyCodes::ALLEGRO_KEY_S;
	InputManager::eventMap[ZOOM_IN] = keyCodes::ALLEGRO_KEY_O;
	InputManager::eventMap[ZOOM_OUT] = keyCodes::ALLEGRO_KEY_P;
	InputManager::eventMap[TOGGLE_RECORD] = keyCodes::ALLEGRO_KEY_R;
}

void InputManager::registerEventSources()
{
	al_register_event_source(EQ, al_get_keyboard_event_source());
	al_register_event_source(EQ, al_get_mouse_event_source());
}

void InputManager::handleEvents()
{
	ALLEGRO_EVENT E;
	while (!al_is_event_queue_empty(EQ)) {
		al_get_next_event(EQ, &E);

		switch (E.type)
		{
		case ALLEGRO_EVENT_KEY_DOWN:
			for (int i = 0; i < AMOUNT_OF_BINDINGS; i++) {
				keyBindings kb = static_cast<keyBindings>(i);
				if (E.keyboard.keycode == eventMap[kb]) {
					if (recording) {
						recordedKeystrokes.push_back({ i, DOWNEVENT });
						std::cout << deltaTicks << std::endl;
						saveDeltaTicks(deltaTicks);
					}
					isKeyDown[kb] = true;
					break;
				}
			}
			break;
		case ALLEGRO_EVENT_KEY_UP:
			for (int i = 0; i < AMOUNT_OF_BINDINGS; i++) {
				keyBindings kb = static_cast<keyBindings>(i);
				if (E.keyboard.keycode == eventMap[kb]) {
					if (recording) {
						recordedKeystrokes.push_back({ i, UPEVENT });
						std::cout << deltaTicks << std::endl;
						saveDeltaTicks(deltaTicks);
					}
					isKeyDown[kb] = false;
					//break;
				}
			}
			if (E.keyboard.keycode == eventMap[TOGGLE_RECORD]) {
				std::reverse(recordedTimings.begin(), recordedTimings.end());
				std::reverse(recordedKeystrokes.begin(), recordedKeystrokes.end());
				replaying = !replaying;
				recording = !recording;
				deltaTicks = 0;
			}
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
			break;
		default:
			break;
		}
	}
}

void InputManager::update()
{
	handleEvents();
	deltaTicks++;
	if (replaying) {
		if (recordedKeystrokes.size() > 0) {
			if (deltaTicks == recordedTimings.back()) {
				std::cout << deltaTicks << std::endl;
				deltaTicks = 0;
				recordedTimings.pop_back();

				keyBindings kb = static_cast<keyBindings>((--recordedKeystrokes.end())->first);
				isKeyDown[kb] = (--recordedKeystrokes.end())->second;
				recordedKeystrokes.pop_back();
			}
		}
		else {
			replaying = false;
			recording = true;
			recordedKeystrokes.clear();
			recordedTimings.clear();
		}
	}
}