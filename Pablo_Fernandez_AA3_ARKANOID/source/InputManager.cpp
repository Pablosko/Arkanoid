#include "InputManager.h"
#include "KeyBoard.h"
InputManager* InputManager::_instance;
InputManager::InputManager()
{
	//player 1
	Keyboard* controller = new Keyboard();
	controller->AddKey(SDLK_ESCAPE, EventKey("Quit"));
	controller->AddKey(SDLK_2, EventKey("2Balls"));
	controller->AddKey(SDLK_1, EventKey("PowerUps"));
	controller->AddKey(SDLK_p, EventKey("Pause"));
	controller->AddKey(SDLK_SPACE, EventKey("Start"));
	controller->AddKey(SDLK_w, EventKey("Up"));
	controller->AddKey(SDLK_s, EventKey("Down"));
	AddController(controller);

	//player 2
	Keyboard* controller2 = new Keyboard();
	controller2->AddKey(SDLK_UP, EventKey("Up"));
	controller2->AddKey(SDLK_DOWN, EventKey("Down"));
	AddController(controller2);
}

InputManager* InputManager::GetInstance()
{
	if (_instance == nullptr)
		_instance = new InputManager();

	return _instance;
}

void InputManager::HandleEvents()
{
	SDL_Event event;
	for (size_t i = 0; i < controllers.size(); i++)
	{
		controllers[i]->ResetReleasedKeys();
		mouseClick = false;
	}
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			mouseClick = true;
		}
		for (size_t i = 0; i < controllers.size(); i++)
		{
			controllers[i]->HandleEvents(event);
		}
	}
}
void InputManager::AddController(Controller* controller)
{
	controllers.push_back(controller);
}
const Vector2D<int>* InputManager::GetMousePosition()
{
	SDL_GetMouseState(&_currentMousePosition.X, &_currentMousePosition.Y);
	return &_currentMousePosition;
}
