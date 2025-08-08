#include <iostream>
#include <SDL2/SDL.h> 
#include "../include/MainLoop.hpp"
#include "../include/Renderer.hpp"
#include "../include/InputSystem.hpp"
#include "../include/UISystem.hpp"
#include "../include/Types.hpp"


void MainLoop::startLoop(){
    while(isRunning){
        inputSystem.checkInput();

        SDL_SetRenderDrawColor(renderer.getSdlRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(renderer.getSdlRenderer());

        Color color; 
        color.r = 255;
        color.g = 0;
        color.b = 0;
        color.alpha = 255;

        Vector start;
        start.x = 0;
        start.y = 0;
        Vector end;
        end.x = 100;
        end.y = 100;

        uiSystem.drawLine(color, start, end);


        SDL_RenderPresent(renderer.getSdlRenderer());

        SDL_Delay(10);
    }
} 

void MainLoop::setIsRunning(bool isRunning){
    this->isRunning = isRunning;
}


MainLoop mainLoop = MainLoop();
