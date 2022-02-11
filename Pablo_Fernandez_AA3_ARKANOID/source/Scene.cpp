#include "Scene.h"
#include "RenderManager.h"
#include  <iostream>

Scene::Scene(SceneManager* _sceneManager)
{
	sceneManager = _sceneManager;
	initialized = false;
	renderManager = new RenderManager(); renderManager->Init();

}

void Scene::Release()
{
	renderManager->Release();
}
void Scene::Update(double elapsedTime)
{
	renderManager->Update(elapsedTime);
}

void Scene::Render()
{
	renderManager->Render();
}

void Scene::Init()
{
	initialized = true;
}
void Scene::Load() 
{

}
void Scene::Unload()
{

}

