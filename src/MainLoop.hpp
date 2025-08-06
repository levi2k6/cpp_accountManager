#include <SDL2/SDL.h>

class MainLoop{
    private:


    public:
        bool running = true;  
        SDL_Event event;

        void startLoop(){

            while(running){
                while(SDL_PollEvent(&event)){
                    if(event.type == SDL_QUIT){
                        running = false;
                    }
                }
            }
        }


};