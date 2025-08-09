#include <iostream>
#include <SDL2/SDL.h> 
#include "../include/WindowDisplay.hpp"
#include "../include/MainLoop.hpp"
#include "../include/Renderer.hpp"
#include "../include/InputSystem.hpp"
#include "../include/UISystem.hpp"
#include "../include/Types.hpp"
#include "../include/Box.hpp"

void MainLoop::startLoop(){
    while(isRunning){
        inputSystem.checkInput();

        SDL_SetRenderDrawColor(renderer.getSdlRenderer(), 0, 0, 0, 255);
        SDL_RenderClear(renderer.getSdlRenderer());

        Color color; 
        color.r = 0;
        color.g = 255;
        color.b = 0;
        color.alpha = 255;

        Vector position;
        position.x = windowDisplay.getSize().x / 2;
        position.y = windowDisplay.getSize().y / 2;
        Vector size;
        size.x = 20;
        size.y = 100;

        

        Box box1(position, size, color); 

        Color color1; 
        color.r = 255;
        color.g = 0;
        color.b = 0;
        color.alpha = 255;

        Vector position1;
        position1.x = 100;
        position1.y = 100;
        Vector size1;
        size1.x = 20;
        size1.y = 100;

        Box box2(position1, size1, color1);

        SDL_RenderPresent(renderer.getSdlRenderer());

        SDL_Delay(10);
    }
} 

void MainLoop::setIsRunning(bool isRunning){
    this->isRunning = isRunning;
}


MainLoop mainLoop = MainLoop();
