#include "Animation2D.h"

Animation2D::Animation2D(std::string _path, RenderManager* renderManager, int total_frames) : Renderer(_path, renderManager)
{
    totalFrames = total_frames;

    sourceRect.x = 0;
    sourceRect.y = 0;
    //no funciona
    sourceRect.h = 60/3;
    sourceRect.w = 200/total_frames;

    renderRect.x = 0;
    renderRect.y = 0;
    renderRect.h = sourceRect.h;
    renderRect.w = sourceRect.w;
    timeBetweenFrames = 0.1f;
}

void Animation2D::Update(double elapsedTime)
{
    currentTime += elapsedTime * speed;
    if (currentTime >= timeBetweenFrames) 
    {
        NextFrame();
        currentTime = 0;
    }
}
void Animation2D::NextFrame() 
{
    _currentFrame++;
    if (_currentFrame >= totalFrames)
    {
            _currentFrame = 0;
        if (!loop)
        {
            speed = 0;
        }
    }
    sourceRect.x = _currentFrame * sourceRect.w;
}

void Animation2D::SetFrame(int frame)
{
    _currentFrame = frame;
}

void Animation2D::Play(float _speed)
{
    speed = _speed;
}
