#include "RankingScene.h"

RankingScene::RankingScene(SceneManager* _sceneManager, Ranking _ranking) : Scene( _sceneManager )
{
	Init();
	rank = _ranking;
	rank.ShowRank(renderManager);
}

void RankingScene::Update(double elapsedTime)
{
	renderManager->Update(elapsedTime);

	if (returnMenu->MouseOver() && InputManager::GetInstance()->mouseClick)
	{
		sceneManager->ChangeScene(new MenuScene(sceneManager));
	}
}

void RankingScene::Init()
{
	Scene::Init();
	GenerateBackground();
	GenerateContent();
}

void RankingScene::GenerateBackground()
{
	SDL_Rect backgroundRect;
	backgroundRect.h = renderManager->ScreenHeight;
	backgroundRect.w = renderManager->ScreenWidth;
	backgroundRect.y = 0;
	backgroundRect.x = 0;
	Image* Background = new Image("resources/MenuBackGround.png", renderManager, backgroundRect);
}

void RankingScene::GenerateContent()
{


	SDL_Rect ButtonRect;
	ButtonRect.h = 60;
	ButtonRect.w = 200;
	ButtonRect.y = renderManager->ScreenHeight * 0.85;
	ButtonRect.x = renderManager->ScreenWidth * 0.38;
	returnMenu = new Button("resources/ButtonImage.png", renderManager, ButtonRect, "Return Menu");
}
