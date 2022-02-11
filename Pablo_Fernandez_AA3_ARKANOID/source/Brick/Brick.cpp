#include "Brick.h"

Brick::Brick(RenderManager* renderManager, int x, int y, int _maxHits, int _points, BrickType type)
{
	animation = new Animation2D("resources/bricks.jpg",renderManager,5);
	position.X = x;
	position.Y = y;
	animation->SetPosition(position.X, position.Y);
	animation->SetSourcePosition(0,(20) * (int)type);
	animation->SetWidth(20, 200/5);
	maxHits = _maxHits;
	hits = 0;
	points = _points;
	invencibleTime = 0.1f;
}

bool Brick::ReciveHit()
{
	invencible = true;
	if (maxHits <= 0) 
	{
		animation->Play(1);
		return false;
	}

	hits += 1;
	animation->NextFrame();

	if (hits >= maxHits) 
	{
		animation->Play(1);
		return true;
	}

	return false;
}

bool Brick::Die(Player* player)
{
	player->score += points;
	animation->active = false;
	return false;
}

void Brick::Update(double elapsedTime)
{
	if (!invencible)
		return;
	currentInvencibleTime += elapsedTime;
	if (currentInvencibleTime >= invencibleTime) 
	{
		invencible = false;
		currentInvencibleTime = 0;
	}

}
