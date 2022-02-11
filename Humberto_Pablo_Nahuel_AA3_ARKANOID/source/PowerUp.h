#pragma once
#include <vector>
#include "Player.h"
#include "Image.h"
#include "GameScene.h"
class GameScene;
class PowerUp
{

public:
	PowerUp(GameScene* _gameScene, SDL_Rect _positionAndSize, RenderManager* renderManager,int dir);
	Image* image;
	Vector2D<float> position;
	Vector2D<float> size;
	GameScene* gameScene;
	SDL_Rect* positionAndSize;

	float direction;
	float speed;
	void virtual Apply(Player* player) = 0;
	void Update(double elapsedTime);
	void SetPosition(float x, float y);
	void SetSize(float w, float h);
	void RemoveMe();

	

};

