#pragma once
#include "Scene.h"
#include <iostream>
#include "Player.h"
#include "Brick/Brick.h"
#include "Ball.h"
#include "Text.h"
#include "CollisionsHelper.h"
#include "PowerUp.h"
enum class GameState 
{
	StartGame,
	Running,
	Pause,
	GameOver
};
class PowerUp;
class GameScene : public Scene
{
public:
	GameScene(SceneManager* _sceneManager);
	int maxBalls;
	GameState state;
	GameState lastState;
	Text* pauseText;
	Text* startGameText;
	Text* GameOverText;
	bool canSpawnPowerUps;
	Text* p1text;
	Text* p2text;
	std::string winnerName;
	//PowerUpFactory* powerUpFactory;
	CollisionsHelper collisionHelper;
	std::vector<Ball*> balls;
	std::vector<Brick*> bricks;
	std::vector<Player*> players;
	std::vector<PowerUp*> powerUps;

	std::vector<Image*> playerLifes;

	Vector2D<float> lastStartingPos;
	Vector2D<float> ball1StartPos;
	Vector2D<float> ball2StartPos;
	
	void CheckCollisions();
	void virtual Update(double elapsedTime) override;
	void virtual Init() override;
	void GeneratePlayerLifesHud(Player* player,float offset);
	void GenerateBackground();
	void GeneratePlayers();
	void GenerateHud();
	void GenerateBricks();
	void GenBall();
	void UpdateLifeHud();
	void UpdateTextHud();
	void SwitchState(GameState newState);
	void SetNextBallStartPos(Ball* ball);
};
