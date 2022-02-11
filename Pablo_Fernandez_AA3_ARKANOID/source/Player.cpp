#include "Player.h"
Player::Player(RenderManager* renderManager)
{
}

Player::Player(SDL_Rect _positionAndSize,RenderManager* renderManager,Controller* _controller)
{
	positionAndSize = new SDL_Rect();
	positionAndSize->x = _positionAndSize.x;
	positionAndSize->y = _positionAndSize.y;
	positionAndSize->w = _positionAndSize.w;
	positionAndSize->h = _positionAndSize.h;
	image = new Image("resources/platform.png", renderManager,*positionAndSize);
	SetPosition(positionAndSize->x, positionAndSize->y);
	SetSize(positionAndSize->w, positionAndSize->h);
	controller = _controller;
	maxhp = 3;
	hp = maxhp;
	speed = 200;
}

void Player::Update(double elapsedTime)
{
	direction = 0;
	if (controller->GetButtonDown("Up"))
		direction = -1;
	if (controller->GetButtonDown("Down"))
		direction = 1;
	if (controller->GetButtonDown("Quit"))
		SDL_Quit();
		

	if (direction != 0)
		position += Vector2D<float>(0, speed * direction * elapsedTime);

	if (position.Y <= topCollision)
		position.Y = topCollision;
	if (position.Y >= botCollision)
		position.Y = botCollision;

	positionAndSize->x = position.X;
	positionAndSize->y = position.Y;
	positionAndSize->w = size.X;
	positionAndSize->h = size.Y;

	SetPosition(position.X, position.Y);
}
void Player::SetCollisionDistance(float top, float bot) 
{
	topCollision = top;
	botCollision = bot;
}
bool Player::GetDamage(float damage)
{
	hp -= damage;
	return (hp <= 0);
		
}
void Player::SetPosition(float x, float y)
{
	position = Vector2D<float>(x,y);
	image->SetPosition(x,y);
}
void Player::SetSize(float w, float h)
{
	size = Vector2D<float>(w, h);
	image->SetWidth(w, h);
}

void Player::Rotate(float a)
{
	rotation += a;
	//position.X = cos(a) * position.X - sin(a) * position.Y;
	//position.Y = sin(a) * position.X + cos(a) * position.Y;
	image->Rotate(a);
}
