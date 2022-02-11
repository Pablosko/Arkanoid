#include "EventKey.h"
EventKey::EventKey(std::string _key, KeyState _state) 
{
	key = _key, state = _state; 
};
EventKey::EventKey(std::string _key)
{
	key = _key, state = KeyState::NonPressed;
};