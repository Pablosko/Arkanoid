#pragma once
#include "Scene.h"
#include <iostream>
#include "Image.h"
class SplashScreen : public Scene
{

public:
	SplashScreen(SceneManager* _sceneManager);
	Image* Background;
	double currentTime;
	double splashTime;
	void virtual Init() override;
	void virtual Update(double elapsedTime) override;
};

