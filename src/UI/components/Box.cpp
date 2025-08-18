#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
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
    std::cout << "Box created without any arguments." << "\n";
};

void Box::drawUi(){

    Vector position;
    Vector size = getSize();
    Color color = getColor();
    int bevel = getBevel();

    if(getParent() == nullptr){
        // std::cout << "No parent" << "\n";
        // std::cout << "Name: " << getName() << "\n";
        position = getPosition();
        // position.print();
    }else{
        // std::cout << "Parent exists" << "\n";
        // std::cout << "Name: " << getName() << "\n";
        position = getInnerPosition();
        // position.print();
    }

    drawFill(position, size, color, bevel);
    filledCircleRGBA(renderer.getSdlRenderer(), position.x, position.y, 4, 0, 255, 0, 255);


    if(getContainerChildren()->size() != 0){
        drawChildren(*getContainerChildren());
    }
}


void Box::drawBorder(){
    
}

void Box::drawFill(Vector &position, Vector &size, Color &color, int &bevel){
     
    int x = position.x - size.x/2;
    int y = position.y - size.y/2;
    int w = size.x;
    int h = size.y;

    roundedBoxRGBA(
        renderer.getSdlRenderer(),
        x, y,
        x + w, y + h,
        bevel, 
        color.r, color.g, color.b, color.alpha
    );
}