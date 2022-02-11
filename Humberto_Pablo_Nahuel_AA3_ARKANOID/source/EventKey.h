#pragma once
#include <string>
#include <map>
#include "SDL.h"
#include "Vector2D.h"
enum class KeyState
{
	NonPressed,
	Pressed,
	Released
};
class EventKey
{
public:
	std::string key;
	KeyState state;
	EventKey() {};
	EventKey(std::string _key, KeyState _state);
	EventKey(std::string _key);
};

