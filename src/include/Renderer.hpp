#pragma once
#include <SDL2/SDL.h>


class Color;
class WindowDisplay;


class Renderer{
    private:
        SDL_Renderer* sdlRenderer;  
    
    public:

        void initRenderer();
        SDL_Renderer* getSdlRenderer();
        void changeColor(const Color &color);

};

extern Renderer renderer;  

