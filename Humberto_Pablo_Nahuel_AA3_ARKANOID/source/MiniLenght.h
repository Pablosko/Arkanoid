#pragma once
#include <vector>
#include "PowerUp.h"

class PowerUp;
class MiniLenght : public PowerUp
{

public:
	float reducedWidth;
	MiniLenght(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir);
	void Apply(Player* player) override;
};

