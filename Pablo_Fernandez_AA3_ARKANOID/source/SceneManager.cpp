#include "SceneManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "SplashScreen.h"


SceneManager::SceneManager()
{
	
	ChangeScene(new MenuScene(this));
}

void SceneManager::ChangeScene(Scene* NewScene)
{
	if(currentScene != nullptr)
		currentScene->Unload();

	currentScene = NewScene;
	if(!currentScene->isInitialized())
		currentScene->Init();
	else
	{
		currentScene->Load();
	}
}
