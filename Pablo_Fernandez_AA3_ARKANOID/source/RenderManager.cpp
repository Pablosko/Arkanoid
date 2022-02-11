#include "RenderManager.h"
#include "Renderer.h"
void RenderManager::AddRenderer(Renderer* r)
{
	renderers.push_back(r);
}

void RenderManager::Render()
{
	SDL_RenderClear(_renderer);
	for (size_t i = 0; i < renderers.size(); i++)
	{
		renderers[i]->Draw(_renderer);
	}
	SDL_RenderPresent(_renderer);
}
void RenderManager::Update(float elapsedTime)
{
	for (size_t i = 0; i < renderers.size(); i++)
	{
		renderers[i]->Update(elapsedTime);
	}
}
void RenderManager::Init() 
{
	CreateWindowAndRenderer();
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
}
void RenderManager::CreateWindowAndRenderer()
{
	SDL_CreateWindowAndRenderer(ScreenWidth, ScreenHeight, SDL_WINDOW_SHOWN, &_window, &_renderer);

	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
}

void RenderManager::Release()
{
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}
