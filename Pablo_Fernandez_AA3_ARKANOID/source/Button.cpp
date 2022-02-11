#include "Button.h"
#include "InputManager.h"
#include <iostream>

void Button::Update(double elapsedTime)
{
}

Button::Button(std::string _path, RenderManager* renderManager, SDL_Rect _renderRect, std::string message) : Renderer(_path, renderManager, _renderRect)
{
    text = new Text("resources/sunspire.ttf", 20, message, renderManager, renderRect);
}

bool Button::MouseOver()
{
	bool state = collisions.IsPointInsideRect(&renderRect, InputManager::GetInstance()->GetMousePosition());
	if(state)
		std::cout <<"MouseOver " << text->message <<std::endl;
	return collisions.IsPointInsideRect(&renderRect, InputManager::GetInstance()->GetMousePosition());
}

void Button::OnClick()
{
	
}
