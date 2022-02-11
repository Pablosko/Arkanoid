#include "Speed.h"

Speed::Speed(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir) : PowerUp(_gameScene, _positionAndSize, renderManager, dir)
{
	extraSpeed = 20;
}

void Speed::Apply(Player* player)
{
	player->speed += player->speed * (extraSpeed / 100);
}

