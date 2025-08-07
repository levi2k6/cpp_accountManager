#pragma once
#include <iostream>
#include <SDL2/SDL.h>

class MainLoop;

class InputSystem{
    private:
        MainLoop* mainLoop;
        SDL_Event event;

    public:
        InputSystem(MainLoop* mainLoop); 
        void checkInput();

    // private: 
    //     MainLoop* mainLoop;
    //     SDL_Event event;

    // public:
    //     InputSystem( MainLoop* mainLoop) : mainLoop(mainLoop){};

    //     void checkInput(){
    //         while(SDL_PollEvent(&event)){
    //             if(event.type == SDL_QUIT){
    //                 mainLoop->setRunning(false);
    //             }

    //             if(event.type == SDL_KEYDOWN){
    //                 if(event.key.keysym.sym == SDLK_f){
    //                     std::cout << "f key is pressed" << "\n";
    //                 }
    //             }
    //         }

    //     }

};

