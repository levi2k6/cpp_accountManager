#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class MainLoop;

class InputSystem{
    private:
        SDL_Event event;

    public:
        void checkInput();

};

extern InputSystem inputSystem;