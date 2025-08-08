#pragma once

#include <iostream>
#include <SDL2/SDL.h>

class WindowDisplay{

    private:
        SDL_Window* window;

    public:
        void initWindow();
        SDL_Window* getWindow();

};

extern WindowDisplay windowDisplay; 