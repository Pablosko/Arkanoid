#include "GameScene.h"
#include "InputManager.h"
#include "PowerUpFactory.h"
#include "AudioManager.h"
#include "MenuScene.h"
GameScene::GameScene(SceneManager* _sceneManager) : Scene(_sceneManager)
{
    Init();
   
    AudioManager::GetInstance()->PlayMusic(AudioManager::GetInstance()->GameMusic);
    maxBalls = 1;
}

void GameScene::Update(double elapsedTime)
{
    if (players[0]->controller->GetButtonUp("2Balls"))
    {
        if (maxBalls == 2)
            maxBalls = 1;
        maxBalls = 2;
    }
    if (players[0]->controller->GetButtonUp("PowerUps"))
    {
        canSpawnPowerUps = true;
    }

    if (players[0]->controller->GetButtonUp("Start"))
    {
        SwitchState(GameState::Running);
    }
    if (players[0]->controller->GetButtonUp("Pause") && state != GameState::GameOver) 
    {
        if (state != GameState::Pause) 
        {
            lastState = state;
            SwitchState(GameState::Pause);
        }
        else
        {
            SwitchState(lastState);
        }

    }
    if (state == GameState::Pause) 
    {
        if (players[0]->controller->GetButtonUp("Quit"))
            sceneManager->ChangeScene(new MenuScene(sceneManager));
    }
    if (state == GameState::Running)
    {
        renderManager->Update(elapsedTime);
        for (int i = 0; i < players.size(); i++)
        {
            players[i]->Update(elapsedTime);
            for (int i = 0; i < balls.size(); i++)
            {
                balls[i]->Update(elapsedTime);
            }
            CheckCollisions();
        }
        for (int i = 0; i < powerUps.size(); i++)
        {
            powerUps[i]->Update(elapsedTime);
        }
        for (int i = 0; i < bricks.size(); i++)
        {
            bricks[i]->Update(elapsedTime);
        }
    }
    if (state == GameState::GameOver) 
    {
        char c = players[0]->controller->GetLastPressedKey();
        if (c != -1)
            winnerName += c;
        GameOverText->UpdateMessage(("Put your name: " + winnerName));
    }

}

void GameScene::Init()
{
    Scene::Init();
    GenerateBackground();
    GeneratePlayers();
    GenerateBricks();
    GenerateHud();
    GenBall();
    SwitchState(GameState::StartGame);
   
}
void GameScene::GenBall()
{
    int ballsCuantity = 2;
    for (int i = 0; i < ballsCuantity; i++)
    {
        float BallCollisionDistanceFromTopScreenLimit = renderManager->ScreenHeight * 0.05f;
        float BallCollisionDistanceFromBotScreenLimit = renderManager->ScreenHeight * 0.68f;
        SDL_Rect ballRect;
        ballRect.h = 20;
        ballRect.w = 20;
        ballRect.y = renderManager->ScreenHeight / 2;
        if (i == 0) 
        {
            ballRect.x = renderManager->ScreenWidth / 4;
            ball1StartPos.X = ballRect.x;
            ball1StartPos.Y = ballRect.y;
        }
        else 
        {
            ballRect.x = renderManager->ScreenWidth - renderManager->ScreenWidth / 4;
            ball2StartPos.X = ballRect.x;
            ball2StartPos.Y = ballRect.y;
        }
        Ball* newBall = new Ball(ballRect, renderManager);
        newBall->playerHit = players[i];
        balls.push_back(newBall);
        balls[i]->SetCollisionDistance(BallCollisionDistanceFromTopScreenLimit, BallCollisionDistanceFromBotScreenLimit);
    }


}
void GameScene::CheckCollisions()
{
    if (balls.size() == 0)
        return;
    for (int i = 0; i < maxBalls; i++)
    {

        if (balls[i]->positionAndSize->x <= 0)
        {
            SetNextBallStartPos(balls[i]);
            if (players[0]->GetDamage(1))
                SwitchState(GameState::GameOver);
            UpdateLifeHud();

        }
        else if (balls[i]->positionAndSize->x >= 800)
        {
            SetNextBallStartPos(balls[i]);
            if (players[1]->GetDamage(1))
                SwitchState(GameState::GameOver);
             UpdateLifeHud();


        }

        if (collisionHelper.IsRectInsideRect(players[0]->positionAndSize, balls[i]->positionAndSize)) 
        {
            balls[i]->playerHit = players[0];
            balls[i]->direction.X *= -1;
            AudioManager::GetInstance()->PlayEffect(AudioManager::GetInstance()->ballHit);

            
        }
        if (collisionHelper.IsRectInsideRect(players[1]->positionAndSize, balls[i]->positionAndSize)) 
        {
            balls[i]->playerHit = players[1];
            balls[i]->direction.X *= -1;
            AudioManager::GetInstance()->PlayEffect(AudioManager::GetInstance()->ballHit);
        }
        for (int b = 0; b < bricks.size(); b++)
        {
            if (collisionHelper.IsRectInsideRect(&bricks[b]->animation->renderRect, balls[i]->positionAndSize)) 
            {
                balls[i]->direction.X *= -1;
                AudioManager::GetInstance()->PlayEffect(AudioManager::GetInstance()->ballHit);
                if (bricks[b]->ReciveHit()) 
                {
                    bricks[b]->Die(balls[i]->playerHit);
                    UpdateTextHud();
                    if(!bricks[i]->spawnedPowerUp)
                     {
                        bricks[i]->spawnedPowerUp = true;
                        int direction = 1;
                        if (players[0] == balls[i]->playerHit)
                            direction = -1;
                       PowerUpFactory* powerUpFactory = new PowerUpFactory();
                       PowerUp *p = powerUpFactory->GenRandomPowerUp(this, bricks[b]->animation->renderRect, renderManager, direction);

                        powerUps.push_back(p);
                    }
                    bricks.erase(bricks.begin() + b);
                }
            }
        }
    }

  
}
void GameScene::GenerateBricks()
{
    int startX = renderManager->ScreenWidth * 0.35;
    int startY = renderManager->ScreenHeight * 0.05;
    for (int y = 0; y < 11; y++)
    {
        for (int x = 0; x < 12; x++)
        {
            int posx = startX + 20 * x;
            int posy = startY + 200/5 * y;
            int maxHits = 0;
            int score = 0;
            int n = (rand() % 100);
            BrickType type = (BrickType)1;
            if (n <= 45) 
            {
                type = BrickType::Green;
                maxHits = 1;
                score = 30;
            }
            else if (n <= 90)
            {
                type = BrickType::Red;
                maxHits = 3;
                score = 100;
            }
            else 
            {
                type = BrickType::Fix;
                maxHits = 0;
            }


            Brick* b = new Brick(renderManager, posx, posy, maxHits, score, type);
            bricks.push_back(b);
        }
    }
}
void GameScene::GenerateBackground()
{
    SDL_Rect backgroundRect;
    backgroundRect.h = renderManager->ScreenHeight;
    backgroundRect.w = renderManager->ScreenWidth;
    backgroundRect.y = 0;
    backgroundRect.x = 0;
    Image* Background = new Image("resources/Background.jpg", renderManager, backgroundRect);
}

void GameScene::GeneratePlayers()
{
    //Relative screen pos
    float PlayerDistanceFromScreenLimits = renderManager->ScreenWidth * 0.035f;
    float PlayerCollisionDistanceFromTopScreenLimit = renderManager->ScreenHeight * 0.05f;
    float PlayerCollisionDistanceFromBotScreenLimit = renderManager->ScreenHeight * 0.68f;

    SDL_Rect player1Rect;
    player1Rect.h = 60;
    player1Rect.w = 20;
    player1Rect.y = renderManager->ScreenHeight / 2 - player1Rect.h / 2;
    player1Rect.x = PlayerDistanceFromScreenLimits;
    Player* player1 = new Player(player1Rect, renderManager, InputManager::GetInstance()->controllers[0]);
    player1->SetCollisionDistance(PlayerCollisionDistanceFromTopScreenLimit, PlayerCollisionDistanceFromBotScreenLimit);
    players.push_back(player1);

    SDL_Rect player2Rect;
    player2Rect.h = 60;
    player2Rect.w = 20;
    player2Rect.y = renderManager->ScreenHeight / 2 - player2Rect.h / 2;
    player2Rect.x = renderManager->ScreenWidth - player2Rect.w - PlayerDistanceFromScreenLimits;
    Player* player2 = new Player(player2Rect, renderManager, InputManager::GetInstance()->controllers[1]);
    player2->SetCollisionDistance(PlayerCollisionDistanceFromTopScreenLimit, PlayerCollisionDistanceFromBotScreenLimit);
    players.push_back(player2);
}

void GameScene::GenerateHud()
{
    for (int i = 0; i < players.size(); i++)
    {
        float playerLife2StartingPosOffset = renderManager->ScreenWidth * 0.484f;
        GeneratePlayerLifesHud(players[i], i * playerLife2StartingPosOffset);
    }

    float startingPosX = renderManager->ScreenWidth * 0.114f;
    float startingPosY = renderManager->ScreenHeight * 0.92f;
    float xOffset = renderManager->ScreenWidth * 0.03f;

    SDL_Rect textPlayer1Rect;
    textPlayer1Rect.h = 50;
    textPlayer1Rect.w = 250;
    textPlayer1Rect.y = renderManager->ScreenHeight * 0.83f;
    textPlayer1Rect.x = renderManager->ScreenWidth * 0.1f;
    p1text = new Text("resources/sunspire.ttf", 20, "P1 0", renderManager, textPlayer1Rect);


    SDL_Rect textPlayer2Rect;
    textPlayer2Rect.h = 50;
    textPlayer2Rect.w = 250;
    textPlayer2Rect.y = renderManager->ScreenHeight * 0.83f;
    textPlayer2Rect.x = renderManager->ScreenWidth * 0.58f;
    p2text = new Text("resources/sunspire.ttf", 20, "P2 0", renderManager, textPlayer2Rect);


    SDL_Rect pauseTextRect;
    pauseTextRect.h = 75;
    pauseTextRect.w = 600;
    pauseTextRect.y = renderManager->ScreenHeight /2 - 70;
    pauseTextRect.x = renderManager->ScreenWidth * 0.12f;
    pauseText = new Text("resources/sunspire.ttf", 20, "Press \"P\" to Resume Game", renderManager, pauseTextRect);

    startGameText = new Text("resources/sunspire.ttf", 20, "Press \"Space\" to Start Game", renderManager, pauseTextRect);

    GameOverText = new Text("resources/sunspire.ttf", 20, "Put your name: ", renderManager, pauseTextRect);

}
void GameScene::GeneratePlayerLifesHud(Player* player, float offset)
{
    float lifeWidth = 60;
    float startingPosX = offset + renderManager->ScreenWidth * 0.114f;
    float startingPosY = renderManager->ScreenHeight * 0.92f;
    float xOffset = lifeWidth + renderManager->ScreenWidth * 0.03f;

    for (int i = 0; i < player->hp; i++)
    {
        SDL_Rect lifeRect;
        lifeRect.h = 20;
        lifeRect.w = lifeWidth;
        lifeRect.y = startingPosY;
        lifeRect.x = startingPosX + xOffset * i;
        Image* life = new Image("resources/life.png", renderManager, lifeRect);
        playerLifes.push_back(life);
    }
}
void GameScene::UpdateLifeHud() 
{
    //hardcoded
    AudioManager::GetInstance()->PlayEffect(AudioManager::GetInstance()->lifeLose);

    playerLifes[0]->active = (players[0]->hp >= 1);
    playerLifes[1]->active = (players[0]->hp >= 2);
    playerLifes[2]->active = (players[0]->hp >= 3);

    playerLifes[3]->active = (players[1]->hp >= 1);
    playerLifes[4]->active = (players[1]->hp >= 2);
    playerLifes[5]->active = (players[1]->hp >= 3);
}

void GameScene::UpdateTextHud()
{
    p1text->UpdateMessage("P1 " + std::to_string(players[0]->score));
    p2text->UpdateMessage("P2 " + std::to_string(players[1]->score));
}

void GameScene::SwitchState(GameState newState)
{
    state = newState;
    if(startGameText != nullptr)
        startGameText->active = newState == GameState::StartGame;
    if (pauseText!= nullptr)
        pauseText->active = newState == GameState::Pause;
    if (GameOverText != nullptr)
        GameOverText->active = newState == GameState::GameOver;



}

void GameScene::SetNextBallStartPos(Ball* ball)
{
    if (maxBalls == 1) 
    {
        if (lastStartingPos.X == ball1StartPos.X || lastStartingPos.X == NULL)
            lastStartingPos = ball2StartPos;
        else
            lastStartingPos = ball1StartPos;

        balls[0]->SetPosition(lastStartingPos.X, lastStartingPos.Y);
    }
    else
    {
        ball->SetPosition(ball->startPosition.X, ball->startPosition.Y);
    }

}
