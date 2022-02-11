#pragma once
#include <string>
#include <map>
#include <vector>
#include "SDL.h"
#include "Vector2D.h"
#include "EventKey.h"
#include "Controller.h"

class InputManager
{
private:
	InputManager();
	Vector2D<int> _currentMousePosition;
	static InputManager* _instance;
public:
	bool mouseClick;
	//publico para pruebas, el controllador lo tedria que tener el player
	std::vector<Controller*> controllers;
	void HandleEvents();
	void AddController(Controller* controller);
	const Vector2D<int>* GetMousePosition();
	static InputManager* GetInstance();
};
