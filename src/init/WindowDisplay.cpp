#include <iostream>
#include "../include/WindowDisplay.hpp"
#include "../include/Types.hpp"

void WindowDisplay::initWindow(){

    char message[] = "Hello SDL";
    size.x = 800;
    size.y = 800;
    
    
    window = SDL_CreateWindow(
        message,
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        size.x,
        size.y,
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

const Vector& WindowDisplay::getSize() const {
    return size;
}

WindowDisplay windowDisplay = WindowDisplay(); 

