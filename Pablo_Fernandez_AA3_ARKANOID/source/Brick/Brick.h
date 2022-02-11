#pragma once
#include "../Animation2D.h"
#include "../Player.h"
#include "../Vector2D.h"
enum class BrickType
{
	Green,
	Red,
	Fix
};
class Brick
{
public:
	Brick(RenderManager* renderManager,int x,int y,int _maxHits,int _points,BrickType type);
	bool invencible;
	float invencibleTime;
	float currentInvencibleTime;
	int maxHits;
	int hits;
	int points;
	Animation2D* animation;
	Vector2D<int> position;
	BrickType type;
	float powerUpChance;
	bool spawnedPowerUp;
	bool ReciveHit();
	bool Die(Player* player);
	void Update(double elapsedTime);
};

