#pragma once
#include "Scene.h"
#include "Button.h"
#include "InputManager.h"
#include "MenuScene.h"
#include "Ranking.h"

class RankingScene : public Scene
{
public:
	RankingScene(SceneManager* _sceneManager, Ranking _rankig);
	Button* returnMenu;
	Ranking rank;
	void virtual Update(double elapsedTime) override;
	void virtual Init() override;
	void GenerateBackground();
	void GenerateContent();

};

