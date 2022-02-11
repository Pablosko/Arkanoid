#include "MenuScene.h"
#include "InputManager.h"
#include "AudioManager.h"
#include "GameScene.h"
MenuScene::MenuScene(SceneManager* _sceneManager) : Scene( _sceneManager)
{
    Init();
    AudioManager::GetInstance()->PlayMusic(AudioManager::GetInstance()->MenuMusic);
}

void MenuScene::Update(double elapsedTime)
{
    renderManager->Update(elapsedTime);

    if (play->MouseOver() && InputManager::GetInstance()->mouseClick)
        sceneManager->ChangeScene(new GameScene(sceneManager));

    if (exit->MouseOver() && InputManager::GetInstance()->mouseClick)
        SDL_Quit();

    if (ranking->MouseOver() && InputManager::GetInstance()->mouseClick)
        sceneManager->ChangeScene(new GameScene(sceneManager));

    if (noSound->MouseOver() && InputManager::GetInstance()->mouseClick)
        AudioManager::GetInstance()->NullAudio();
}

void MenuScene::Init()
{
    Scene::Init();
    GenerateBackground();
    GenerateHud();
}
void MenuScene::GenerateBackground()
{
    SDL_Rect backgroundRect;
    backgroundRect.h = renderManager->ScreenHeight;
    backgroundRect.w = renderManager->ScreenWidth;
    backgroundRect.y = 0;
    backgroundRect.x = 0;
    Image* Background = new Image("resources/MenuBackGround.png", renderManager, backgroundRect);
}

void MenuScene::GenerateHud()
{
    SDL_Rect ButtonRect;
    ButtonRect.h = 75;
    ButtonRect.w = 150;
    ButtonRect.y = renderManager->ScreenHeight * 0.3;
    ButtonRect.x = renderManager->ScreenWidth * 0.4;
    play = new Button("resources/ButtonImage.png", renderManager, ButtonRect, "Play");


    SDL_Rect rankingRect;
    rankingRect.h = 75;
    rankingRect.w = 150;
    rankingRect.y = renderManager->ScreenHeight * 0.45;
    rankingRect.x = renderManager->ScreenWidth * 0.4;
    ranking = new Button("resources/ButtonImage.png", renderManager, rankingRect, "Ranking");

    SDL_Rect noSoundRect;
    noSoundRect.h = 75;
    noSoundRect.w = 150;
    noSoundRect.y = renderManager->ScreenHeight * 0.6;
    noSoundRect.x = renderManager->ScreenWidth * 0.4;
    noSound = new Button("resources/ButtonImage.png", renderManager, noSoundRect, "No Sound");

    SDL_Rect exitRect;
    exitRect.h = 75;
    exitRect.w = 150;
    exitRect.y = renderManager->ScreenHeight * 0.75;
    exitRect.x = renderManager->ScreenWidth * 0.4;
    exit = new Button("resources/ButtonImage.png", renderManager, exitRect, "Exit");
}
