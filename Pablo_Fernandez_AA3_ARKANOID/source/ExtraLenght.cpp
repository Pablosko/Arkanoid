#include "ExtraLenght.h"

ExtraLenght::ExtraLenght(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager,int dir) : PowerUp(_gameScene,_positionAndSize,renderManager, dir)
{
	extraLenght = 25;
}

void ExtraLenght::Apply(Player* player)
{
	float h = player->positionAndSize->h ;
	h = h + h * extraLenght/100;
	player->SetSize(player->positionAndSize->w , h);

}

