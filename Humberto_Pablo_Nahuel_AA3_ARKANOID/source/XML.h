#pragma once
#include "Brick/Brick.h"
#include <vector>
#include <string>
#include "Vector2D.h"
class LoadXML
{
public:
	LoadXML();
	std::vector<Vector2D<int>> positions;
	std::vector<BrickType> types;
};

