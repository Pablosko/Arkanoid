#include "Renderer.h"

Renderer::Renderer(std::string _path, RenderManager* renderManager)
{
    SDL_Surface* surface = IMG_Load(_path.c_str());
    texture = SDL_CreateTextureFromSurface(renderManager->_renderer, surface);

    SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);

    sourceRect.x = 0;
    sourceRect.y = 0;

    renderRect.x = 0;
    renderRect.y = 0;
    renderRect.h = renderRect.h;
    renderRect.w = renderRect.w;
    active = true;
    renderManager->AddRenderer(this);
}
Renderer::Renderer(std::string _path, RenderManager* renderManager, SDL_Rect _renderRect)
{
    renderRect = _renderRect;
    SDL_Surface* surface = IMG_Load(_path.c_str());
    texture = SDL_CreateTextureFromSurface(renderManager->_renderer, surface);

    SDL_QueryTexture(texture, nullptr, nullptr, &sourceRect.w, &sourceRect.h);

    sourceRect.x = 0;
    sourceRect.y = 0;

    renderRect.h = renderRect.h;
    renderRect.w = renderRect.w;
    active = true;
    renderManager->AddRenderer(this);
}
void Renderer::SetPosition(float x, float y)
{
    renderRect.x = x;
    renderRect.y = y;
}
void Renderer::SetSourcePosition(float x, float y)
{
    //Hardcoded para animacion
    sourceRect.x = x;
    sourceRect.y = y;
    sourceRect.w = 40;
    sourceRect.h = 20;
}
void Renderer::SetWidth(float w, float h)
{
    renderRect.w = w;
    renderRect.h = h;
}
void Renderer::Rotate(double a)
{
    angle += a;
}
void Renderer::Draw(SDL_Renderer* _renderer)
{

    if(active)
        SDL_RenderCopyEx(_renderer, texture, &sourceRect, &renderRect, angle, nullptr, flip);
}
void Renderer::SetAlpha(double a)
{
    SDL_SetTextureAlphaMod(texture, a);
}
