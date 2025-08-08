#include <iostream>
#include "../include/WindowDisplay.hpp"

void WindowDisplay::initWindow(){

    char message[] = "Hello SDL";
    float width = 500;
    float height = 500;
    
    window = SDL_CreateWindow(
        message,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if(!window){
        std::cerr << "Creating window failed:  " << SDL_GetError() << "\n";
        SDL_Quit();
    }
}

SDL_Window* WindowDisplay::getWindow(){
    return window;
}


WindowDisplay windowDisplay = WindowDisplay(); 

