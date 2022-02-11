#pragma once

#include "Brick/Brick.h"
#include <vector>

class LoadXML
{

public:
	std::vector<Brick*> bricks;
	LoadXML();
	std::vector<Brick*> GetBricks() { return bricks; }
};

