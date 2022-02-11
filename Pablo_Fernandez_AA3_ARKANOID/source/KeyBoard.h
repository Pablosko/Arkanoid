#pragma once
#include "Controller.h"
class Keyboard : public Controller
{
private:
	std::map<SDL_Keycode, EventKey> SDL_Key_Event;
public:
	Keyboard() : Controller() {};
	virtual void HandleEvents(const SDL_Event) override;
	void ResetReleasedKeys() override;
	void AddKey(SDL_Keycode k, EventKey e) override;
	virtual const bool GetButtonDown(std::string actionId) override;
	virtual const bool GetButtonUp(std::string actionId) override;
	virtual const float GetButtonAxis(std::string actionId) override;
};

