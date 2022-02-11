#pragma once
#include <string>
#include <map>
#include "SDL.h"
#include "Vector2D.h"
#include "EventKey.h"
class Controller
{
protected:
	char lastPressedKey;
private:
	std::map<SDL_Keycode, EventKey> SDL_Key_Event;
public:
	Controller() {};
	virtual void HandleEvents(const SDL_Event) = 0;
	virtual void ResetReleasedKeys() = 0;
	virtual void AddKey(SDL_Keycode k, EventKey e) = 0;
	virtual const bool GetButtonDown(std::string actionId) = 0;
	virtual const bool GetButtonUp(std::string actionId) = 0;
	virtual const float GetButtonAxis(std::string actionId) = 0;
	const char GetLastPressedKey();
};
