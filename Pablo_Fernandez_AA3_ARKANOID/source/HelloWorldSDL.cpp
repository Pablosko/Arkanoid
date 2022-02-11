#include <stdio.h>
#include <exception>
#include <chrono>
#include "Game.h"
#include "Image.h"
#include <iostream>


int main(int argc, char* args[]) {
    auto game = Game();
    try {
        game.Init();

        auto lastTime = std::chrono::system_clock::now();
        while (game.IsRunning()) {
            auto currentTime = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsedTime = currentTime - lastTime;
            lastTime = currentTime;

            //Mirar eventos
            game.HandleEvents();

            //Pintarlos
            game.Render();

            //Reaccionar a los eventos
            game.Update(elapsedTime.count());
        }

        game.Release();
    }
    catch (std::exception& exception) {
        fprintf(stderr, exception.what());
        SDL_Quit();
        return -1;
    }
    return 0;
}
