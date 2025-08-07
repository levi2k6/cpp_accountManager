#include <iostream>
#include "../include/MainLoop.hpp"
#include "../include/InputSystem.hpp"

MainLoop::MainLoop() : inputSystem(new InputSystem(this)){}

void MainLoop::startLoop(){
    while(isRunning){
        inputSystem->checkInput();
    }
} 

void MainLoop::setIsRunning(bool isRunning){
    this->isRunning = isRunning;
}

