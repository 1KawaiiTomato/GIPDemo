#include "InputManager.h"

std::unordered_map<InputManager::keyBindings, keyCodes>InputManager::eventMap;
tinyxml2::XMLDocument InputManager::XMLDoc;
bool InputManager::recording;
std::vector<int>InputManager::recordedKeystrokes;

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
	loadFromFile("Data/keyBindings.xml");
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
}
