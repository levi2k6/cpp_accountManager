#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include "../../include/Container.hpp"
#include "../../include/Types.hpp"

Container::Container(std::string name) : UI(name){
    onStart();
}

Container::Container( std::string name, Vector position, Vector size, Color color) : UI(name, position, size, color){
    onStart();
}

void Container::onStart(){
};

void Container::drawUi(){

}

void Container::addChild(std::unique_ptr<UI> child){
}

void Container::drawChildren(){
}