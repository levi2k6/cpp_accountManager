#include <iostream>
#include <SDL2/SDL.h> 
#include "../include/WindowDisplay.hpp"
#include "../include/MainLoop.hpp"
#include "../include/Renderer.hpp"
#include "../include/InputSystem.hpp"
#include "../include/UISystem.hpp"
#include "../include/SceneSystem.hpp"
#include "../include/Types.hpp"
#include "../include/Box.hpp"

void MainLoop::startLoop(){
    while(isRunning){
        inputSystem.checkInput();

        SDL_SetRenderDrawColor(renderer.getSdlRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(renderer.getSdlRenderer());

        sceneSystem.sceneChanger();

        SDL_RenderPresent(renderer.getSdlRenderer());
        SDL_Delay(10);
    }
} 

void MainLoop::setIsRunning(bool isRunning){
    this->isRunning = isRunning;
}


MainLoop mainLoop = MainLoop();
