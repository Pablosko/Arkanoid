#include "PowerUp.h"

PowerUp::PowerUp(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager, int dir)
{
	gameScene = _gameScene;
	positionAndSize = new SDL_Rect();
	positionAndSize->x = _positionAndSize.x;
	positionAndSize->y = _positionAndSize.y;
	positionAndSize->w = _positionAndSize.w;
	positionAndSize->h = _positionAndSize.h;
	image = new Image("resources/platform.png", renderManager, *positionAndSize);
	SetPosition(positionAndSize->x, positionAndSize->y);
	SetSize(positionAndSize->w, positionAndSize->h);
	speed = 125;
	direction = dir;


}
void PowerUp::Update(double elapsedTime)
{
	position += Vector2D<float>(speed * direction * elapsedTime,0);
	
	for (int i = 0; i < gameScene->players.size(); i++)
	{
		if (gameScene->collisionHelper.IsRectInsideRect(gameScene->players[i]->positionAndSize, positionAndSize)) 
		{
			Apply(gameScene->players[i]);
			RemoveMe();
		}
	}
	if (positionAndSize->x < 0 || positionAndSize->x > 800) 
	{
		RemoveMe();
	}



	positionAndSize->x = position.X;
	positionAndSize->y = position.Y;
	positionAndSize->w = size.X;
	positionAndSize->h = size.Y;

	SetPosition(position.X, position.Y);
}
void PowerUp::SetPosition(float x, float y)
{
	position = Vector2D<float>(x, y);
	image->SetPosition(x, y);
}
void PowerUp::SetSize(float w, float h)
{
	size = Vector2D<float>(w, h);
	image->SetWidth(w, h);
}
void PowerUp::RemoveMe()
{
	std::vector<PowerUp*>::iterator me;
	for (std::vector<PowerUp*>::iterator it = gameScene->powerUps.begin(); it != gameScene->powerUps.end(); ++it)
	{
		if (*it == this)
			me = it;
	}
	gameScene->powerUps.erase(me);
	image->active = false;
}