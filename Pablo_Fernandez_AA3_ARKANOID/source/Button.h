#pragma once

#include "Renderer.h"
#include "Text.h"
#include "Image.h"
#include "Scene.h"
#include <vector>
#include "CollisionsHelper.h"

class Button : public Renderer
{
	CollisionsHelper collisions;
public:
	Text* text;
	Scene* nextScene;
	void Update(double elapsedTime) override;
	Button(const std::string _path, RenderManager* renderManager, SDL_Rect _renderRect,std::string message);
	bool MouseOver();
	void OnClick();
};

