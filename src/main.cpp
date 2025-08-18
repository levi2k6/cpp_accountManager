#include <iostream>
#include "utils.hpp"
#include <SDL2/SDL.h>

#include "./include/WindowDisplay.hpp"
#include "./include/Renderer.hpp"
#include "./include/MainLoop.hpp"
#include "./include/SceneInit.hpp"
#include "./include/UILayoutSystem.hpp"

int main(){
    windowDisplay.initWindow(); 
    renderer.initRenderer();
    sceneInit.initAllScenes();
    mainLoop.startLoop();

    SDL_DestroyWindow(windowDisplay.getWindow());
    SDL_Quit();
    return 0;
}

