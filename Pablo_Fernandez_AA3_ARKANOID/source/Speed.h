#pragma once
#include <vector>
#include "PowerUp.h"

class PowerUp;
class Speed : public PowerUp
{

public:
	Speed(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir);
	float extraSpeed;
	void Apply(Player* player) override;

};

