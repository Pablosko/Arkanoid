#include "MiniLenght.h"

MiniLenght::MiniLenght(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir) : PowerUp(_gameScene, _positionAndSize, renderManager, dir)
{
	reducedWidth = 25;
}

void MiniLenght::Apply(Player* player)
{
	float h = player->positionAndSize->h;
	player->SetSize(player->positionAndSize->w, h * (100 -reducedWidth) / 100);

}

