#pragma once
#include <SDL.h>
#include "RenderManager.h"
#include "Player.h"
#include "GameScene.h"
#include "SceneManager.h"
class Player;
class Game
{
public:

	Game() = default;
	void InitScenes(); 
	void Init();
	void InitBricks();
	void InitBall();
	void InitSDL();
	void HandleEvents();
	void Update(double elapsedTime);
	void Release();
	void Render();
	bool IsRunning();
	
	SceneManager* sceneManager;

private:
	bool _isRunning;
};

