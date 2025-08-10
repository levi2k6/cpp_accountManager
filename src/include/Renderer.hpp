#pragma once
#include <SDL2/SDL.h>
#include "Types.hpp" 


class Color;
class WindowDisplay;


class Renderer{
    private:
        SDL_Renderer *sdlRenderer;  

    
    public:

        void initRenderer();
        SDL_Renderer* getSdlRenderer();
        void changeColor(const Color &color);
        void drawLine(const Vector& start, const Vector& end);
        void drawPoint(const Vector& position);
        void drawCircle(int centerX, int centerY, int radius); 
        void createBox(const Vector& position , const Vector& size);
};

extern Renderer renderer;  

