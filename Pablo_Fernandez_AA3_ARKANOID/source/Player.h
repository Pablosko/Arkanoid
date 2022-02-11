#pragma once
#include "Controller.h"
#include "Vector2D.h"
#include "Image.h"
#include "CollisionsHelper.h"
class Player
{
private:
	Image* image;
	Vector2D<float> position;
	Vector2D<float> size;
	float rotation;
	float topCollision;
	float botCollision;
public:
	SDL_Rect* positionAndSize;
	Controller* controller;
	Player(RenderManager* renderManager);
	Player(SDL_Rect _positionAndSize, RenderManager* renderManager,Controller* controller);
	void Update(double elapsedTime);
	void SetPosition(float x, float y);
	void SetSize(float w, float h);
	void Rotate(float a);
	void SetCollisionDistance(float top, float bot);
	bool GetDamage(float damage);

	float direction;
	float speed;
	int hp;
	int maxhp;
	int score;
};