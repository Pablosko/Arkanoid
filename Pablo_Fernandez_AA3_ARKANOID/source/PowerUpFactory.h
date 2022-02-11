#pragma once
#include <vector>
#include "Speed.h"
#include "ExtraLenght.h"
#include "MiniLenght.h"
class MiniLenght;
class ExtraLenght;
class Speed;
class PowerUpFactory
{

public:
	PowerUpFactory();
	PowerUp* GenRandomPowerUp(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir);
};

