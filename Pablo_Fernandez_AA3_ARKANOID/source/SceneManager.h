#pragma once
#include "Scene.h"

class Scene;
class SceneManager
{
public:
	SceneManager();
	Scene* currentScene;
	void ChangeScene(Scene* NewScene);
};

