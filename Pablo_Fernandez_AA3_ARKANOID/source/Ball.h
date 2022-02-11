#pragma once
#include "Player.h"
class Player;
class Ball
{

private:
	Image* image;
	Vector2D<float> position;
	Vector2D<float> size;
	float rotation;
	float topCollision;
	float botCollision;
public:
	Vector2D<float> startPosition;
	SDL_Rect* positionAndSize;
	Ball(RenderManager* renderManager);
	Ball(SDL_Rect _positionAndSize, RenderManager* renderManager);
	void Update(double elapsedTime);
	void SetPosition(float x, float y);
	void SetSize(float w, float h);
	void Rotate(float a);
	void SetCollisionDistance(float top, float bot);
	Player* playerHit;
	Vector2D<float> direction;
	float speed;
	int score;
};

