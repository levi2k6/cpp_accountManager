#pragma once
#include <SDL2/SDL.h>

class MainLoop{
    private:
        bool isRunning = true;  

    public:
        void startLoop();
        void setIsRunning(bool isRunning); 
};

extern MainLoop mainLoop;
