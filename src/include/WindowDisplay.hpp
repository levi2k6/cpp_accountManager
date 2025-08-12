#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include "../include/Types.hpp"


class WindowDisplay{

    private:
        SDL_Window *window;
        Vector size = Vector(800, 800); 

    public:
        void initWindow();
        SDL_Window* getWindow();
        Vector getSize();
};

extern WindowDisplay windowDisplay; 