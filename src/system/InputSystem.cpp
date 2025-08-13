#include <iostream> 
#include "../include/InputSystem.hpp"
#include "../include/MainLoop.hpp"

void InputSystem::checkInput(){
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            mainLoop.setIsRunning(false);
        } 
        if(event.type == (SDL_KEYDOWN)){
            if(event.key.keysym.sym == SDLK_f){
                std::cout << "You are pressing F." << "\n";
            } 
        }

    }
}

InputSystem inputSystem = InputSystem();


