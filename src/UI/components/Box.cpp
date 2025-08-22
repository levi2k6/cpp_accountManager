#include <SDL2/SDL.h>
#include "../../include/Box.hpp"
#include "../../include/Types.hpp"

Box::Box(std::string name) : Container(name){
    onStart();
}

Box::Box( std::string name, Vector position, Vector size, Color color, int bevel)
: Container(name, position, size, color, bevel)
{
    onStart();
}

void Box::onStart(){
};




