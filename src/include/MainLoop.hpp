#include <SDL2/SDL.h>

class InputSystem; 

class MainLoop{
    private:
        InputSystem* inputSystem;   
        bool isRunning = true;  

    public:
        MainLoop();
        void startLoop();
        void setIsRunning(bool isRunning); 

        
    // private:
    
    // public:
    //     MainLoop() : inputSystem(this){
    //     } 

    //     void startLoop(){
    //         while(running){
    //             this->inputSystem.checkInput();
    //         }
    //     }

    //     bool getRunning(){
    //         return running;
    //     } 

    //     void setRunning(bool running){
    //         this->running = running;
    //     }
};