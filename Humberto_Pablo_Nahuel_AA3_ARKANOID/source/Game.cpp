#include <SDL.h>
#include "InputManager.h"
#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include <cmath> 
#include <SDL_ttf.h>

void Game::Init()
{
    InitSDL();
    TTF_Init();
    InitScenes();

    _isRunning = true;
}
void Game::InitScenes()
{
    sceneManager = new SceneManager();
}
void Game::InitSDL() {
    int result = SDL_Init(SDL_INIT_VIDEO);
    auto isInitialized = result >= 0;

    //Check for errors
    if (!isInitialized) {
        throw SDL_GetError();
    }
}

void Game::HandleEvents()
{
    InputManager::GetInstance()->HandleEvents();
}

void Game::Update(double elapsedTime)
{
    sceneManager->currentScene->Update(elapsedTime);
}


void Game::Release()
{
    sceneManager->currentScene->Release();
    SDL_Quit();
}

void Game::Render()
{
    if(sceneManager != nullptr)
        if (sceneManager->currentScene != nullptr)
            sceneManager->currentScene->Render();
}

bool Game::IsRunning()
{
    return _isRunning;
}

