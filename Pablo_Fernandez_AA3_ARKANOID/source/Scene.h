#pragma once
#include <string>
#include <map>
#include "AudioManager.h"
#include "SceneManager.h"
class RenderManager;
class SceneManager;
class Scene
{
private:
	bool initialized;
public:
	Scene(SceneManager* _sceneManager);
	SceneManager* sceneManager;
	RenderManager* renderManager;
	Mix_Music* backgroundMusic;
	void Release();
	bool isInitialized() { return initialized; }
	void Render();
	void virtual Update(double elapsedTime);
	void virtual Init();
	void Unload();
	void Load();
};
