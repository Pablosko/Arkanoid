#include "Ball.h"
Ball::Ball(RenderManager* renderManager)
{
}

Ball::Ball(SDL_Rect _positionAndSize, RenderManager* renderManager)
{
	positionAndSize = new SDL_Rect();
	positionAndSize->x = _positionAndSize.x;
	positionAndSize->y = _positionAndSize.y;
	positionAndSize->w = _positionAndSize.w;
	positionAndSize->h = _positionAndSize.h;

	startPosition.X = positionAndSize->x;
	startPosition.Y = positionAndSize->y;

	image = new Image("resources/ball.png", renderManager, *positionAndSize);
	SetPosition(startPosition.X, startPosition.Y);
	SetSize(positionAndSize->w, positionAndSize->h);
	speed = 75;
	direction.X = 1;
	direction.Y = 1;
}

void Ball::Update(double elapsedTime)
{

	if (direction.X != 0 || direction.Y != 0)
		position += Vector2D<float>(speed * direction.X * elapsedTime, speed * direction.Y * elapsedTime);

	if (position.Y <= topCollision)
		direction.Y = direction.Y = 1;
	if (position.Y >= botCollision + positionAndSize->w + 10)
		direction.Y = direction.Y = -1;



	positionAndSize->x = position.X;
	positionAndSize->y = position.Y;
	positionAndSize->w = size.X;
	positionAndSize->h = size.Y;

	SetPosition(position.X, position.Y);
}
void Ball::SetCollisionDistance(float top, float bot)
{
	topCollision = top;
	botCollision = bot;
}
void Ball::SetPosition(float x, float y)
{
	position = Vector2D<float>(x, y);
	image->SetPosition(x, y);
}
void Ball::SetSize(float w, float h)
{
	size = Vector2D<float>(w, h);
	image->SetWidth(w, h);
}

void Ball::Rotate(float a)
{
	rotation += a;
	//position.X = cos(a) * position.X - sin(a) * position.Y;
	//position.Y = sin(a) * position.X + cos(a) * position.Y;
	image->Rotate(a);
}
