#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cmath> 
#include "RenderManager.h"
class RenderManager;
class Renderer
{
protected:
	SDL_Texture* texture;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	double angle = 0;

public:
	SDL_Rect renderRect;
	SDL_Rect sourceRect;
	Renderer() { active = true; };
	Renderer(const std::string _path, RenderManager* renderManager);
    Renderer(const std::string _path, RenderManager* renderManager, SDL_Rect _renderRect);
	virtual void Update(double elapsedTime) = 0;
	virtual void SetPosition(float x, float y);
	virtual void SetSourcePosition(float x, float y);
	virtual void SetWidth(float w, float h);
	void Rotate(double a);
	bool active;
	virtual void Draw(SDL_Renderer* _renderer);
	void SetAlpha(double a);
};

