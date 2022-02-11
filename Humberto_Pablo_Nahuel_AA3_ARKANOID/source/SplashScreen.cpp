#include "SplashScreen.h"
#include "MenuScene.h"


SplashScreen::SplashScreen(SceneManager* _sceneManager) : Scene(_sceneManager)
{
    splashTime = 3;
	Init();
}
void SplashScreen::Init()
{
    SDL_Rect backgroundRect;
    backgroundRect.h = renderManager->ScreenHeight;
    backgroundRect.w = renderManager->ScreenWidth;
    backgroundRect.y = 0;
    backgroundRect.x = 0;
	Background = new Image("resources/SplashScreen.png", renderManager, backgroundRect);
}
void SplashScreen::Update(double elapsedTime)
{
    currentTime += elapsedTime;
    if (currentTime >= splashTime)
        sceneManager->ChangeScene(new MenuScene(sceneManager));
    if(Background != nullptr)
         Background->SetAlpha(currentTime / splashTime);
    renderManager->Update(elapsedTime);
}

