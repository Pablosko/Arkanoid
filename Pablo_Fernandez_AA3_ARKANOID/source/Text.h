#pragma once
#include "Renderer.h"
#include <SDL_ttf.h>
class Text : public Renderer
{
	SDL_Texture* texture;
	SDL_Rect renderRect;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	SDL_Rect sourceRect;

	TTF_Font* font;
	SDL_Color color;
	SDL_Surface* surface;
	RenderManager* renderManager;
public:
	std::string message;
	virtual void Update(double elapsedTime) override;
	Text(const std::string _path, int fontSize, std::string _message, RenderManager* _renderManager, SDL_Rect _renderRect);
	void UpdateMessage(std::string newMessage);
	virtual void Draw(SDL_Renderer* _renderer) override;
};
