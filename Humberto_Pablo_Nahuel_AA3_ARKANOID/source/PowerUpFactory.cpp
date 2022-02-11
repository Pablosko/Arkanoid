#include "PowerUpFactory.h"

PowerUpFactory::PowerUpFactory()
{
	
}

PowerUp* PowerUpFactory::GenRandomPowerUp(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir)
{
    int r = (rand() % 3);
    switch (r)
    {
    case 0:
        return new Speed(_gameScene, _positionAndSize, renderManager, dir);
        break;
    case 1:
        return new MiniLenght(_gameScene, _positionAndSize, renderManager, dir);
        break;
    case 2:
        return new ExtraLenght(_gameScene, _positionAndSize, renderManager, dir);
        break;
    }
}
