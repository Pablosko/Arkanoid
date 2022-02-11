#pragma once
#include "Scene.h"
#include <iostream>
#include "Button.h"

class MenuScene : public Scene
{
public:
	MenuScene(SceneManager* _sceneManager);
	
	Button* play;
	Button* ranking;
	Button* exit;
	Button* noSound;
	
	void virtual Update(double elapsedTime) override;
	void virtual Init() override;
	void GenerateHud();
	void GenerateBackground();
};
