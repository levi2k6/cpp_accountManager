#pragma once
#include <SDL2/SDL.h>

class WindowDisplay;

class Renderer{
    private:
        SDL_Renderer* sdlRenderer;  
    
    public:

        void initRenderer();
        SDL_Renderer* getSdlRenderer();
};

extern Renderer renderer;  

