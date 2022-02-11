#include "KeyBoard.h"
#include  <iostream>

void Keyboard::HandleEvents(const SDL_Event event)
{
	if (event.key.type == SDL_KEYDOWN)
	{
		auto key = event.key.keysym.sym;
		lastPressedKey = key;
		if (SDL_Key_Event[key].state == KeyState::NonPressed)
		{
			std::cout << key << " Pressed" << std::endl;;
			SDL_Key_Event[key].state = KeyState::Pressed;
		}
	}
	else if (event.key.type == SDL_KEYUP)
	{
		auto key = event.key.keysym.sym;
		if (SDL_Key_Event[key].state == KeyState::Pressed) 
		{
			std::cout << key << " Released" << std::endl;
				SDL_Key_Event[key].state = KeyState::Released;
		}
	}
}
void Keyboard::ResetReleasedKeys()
{
	lastPressedKey = -1;
	std::map<SDL_Keycode, EventKey>::iterator it;
	for (it = SDL_Key_Event.begin(); it != SDL_Key_Event.end(); it++)
	{
		if (it->second.state == KeyState::Released) 
		{
			std::cout << "pressed key is now" << " NonPressed" << std::endl;
			it->second.state = KeyState::NonPressed;
		}
	}
}
void Keyboard::AddKey(SDL_Keycode k, EventKey e)
{
	SDL_Key_Event[k] = e;
}
const bool Keyboard::GetButtonDown(std::string actionId)
{
	std::map<SDL_Keycode, EventKey>::iterator it;
	for (it = SDL_Key_Event.begin(); it != SDL_Key_Event.end(); it++)
	{
		if (it->second.key == actionId)
		{
			return it->second.state == KeyState::Pressed;
		}
	}
	return false;
}


const bool Keyboard::GetButtonUp(std::string actionId)
{
	std::map<SDL_Keycode, EventKey>::iterator it;
	for (it = SDL_Key_Event.begin(); it != SDL_Key_Event.end(); it++)
	{
		if (it->second.key == actionId)
			return it->second.state == KeyState::Released;
	}
	return false;
}

const float Keyboard::GetButtonAxis(std::string actionId)
{
	return 0.0f;
}
