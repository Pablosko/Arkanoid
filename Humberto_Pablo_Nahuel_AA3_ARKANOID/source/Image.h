#pragma once
#include "Renderer.h"
class Image : public Renderer
{
public:
	virtual void Update(double elapsedTime) override;
	Image(const std::string _path, RenderManager* renderManager) : Renderer(_path, renderManager) {};
	Image(const std::string _path, RenderManager* renderManager, SDL_Rect _renderRect) : Renderer(_path, renderManager, _renderRect) {};
};
