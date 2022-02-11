#include "Text.h"


void Text::Update(double elapsedTime)
{

}
Text::Text(const std::string _path, int fontSize ,std::string _message, RenderManager* _renderManager, SDL_Rect _renderRect) : Renderer()
{
    font = TTF_OpenFont(_path.c_str(), fontSize);
    auto error = SDL_GetError();
    color = { 0, 0, 0 };
    message = _message;
    surface = TTF_RenderText_Solid(font,  message.c_str(), color);
    renderManager = _renderManager;
    texture = SDL_CreateTextureFromSurface(renderManager->_renderer, surface);

    renderRect = _renderRect;
    //SDL_FreeSurface(surfaceMessage);
    //SDL_DestroyTexture(texture);
    renderManager->AddRenderer(this);
}

void Text::UpdateMessage(std::string newMessage)
{
    message = newMessage;
    surface = TTF_RenderText_Solid(font, message.c_str(), color);
    texture = SDL_CreateTextureFromSurface(renderManager->_renderer, surface);
}

void Text::Draw(SDL_Renderer* _renderer)
{
    if(active)
        SDL_RenderCopy(_renderer, texture, NULL, &renderRect);
}
