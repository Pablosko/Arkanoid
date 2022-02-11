#pragma once
#include <vector>
#include "PowerUp.h"

class PowerUp;
class ExtraLenght : public PowerUp
{

public:
	float extraLenght;
	ExtraLenght(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir);
	void Apply(Player* player) override;

};

