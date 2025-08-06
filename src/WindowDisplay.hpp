#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class WindowDisplay{

    private:

    public:
        SDL_Window* window;
        
        void initWindow(){

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



};