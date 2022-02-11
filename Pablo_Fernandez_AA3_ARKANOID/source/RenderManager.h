#pragma once
#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <iostream>
#include <cmath> 
#include <vector>
class Renderer;
class RenderManager
{
private:
	std::vector<Renderer*> renderers;
	SDL_Window* _window;

public:
	const int ScreenWidth = 800;
	const int ScreenHeight = 600;
	SDL_Renderer* _renderer;
	void Init();
	void Update(float elapsedTime);
	void Render();
	void CreateWindowAndRenderer();
	void Release();
	void AddRenderer(Renderer* r);
	
};

