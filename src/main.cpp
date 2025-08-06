#include <iostream>
#include "utils.hpp"
#include <SDL2/SDL.h>

#include "WindowDisplay.hpp"
#include "MainLoop.hpp"

WindowDisplay windowDisplay = WindowDisplay();
MainLoop mainLoop = MainLoop();


int main(){

    windowDisplay.initWindow(); 
    mainLoop.startLoop();

    SDL_DestroyWindow(windowDisplay.window);
    SDL_Quit();
    return 0;
}

