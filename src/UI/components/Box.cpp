#include <SDL2/SDL.h>
#include "../../include/Box.hpp"
#include "../../include/Types.hpp"

Box::Box(std::string name) : Container(name){
    onStart();
}

Box::Box( std::string name, Vector position, Vector size, Color color) : Container(name, position, size, color){
    onStart();
}

void Box::onStart(){
    std::cout << "Box created without any arguments." << "\n";
};

void Box::drawUi(){

    Vector position;
    if(getParent() == nullptr){
        position = getPosition();
    }else{
        position = getInnerPosition();
    }

    Vector size = getSize();
    Color color = getColor();

    renderer.changeColor(color);

    Vector heightPosition(position.x - size.x, position.y - size.y);// x, y

    Vector downLeftPosition(position.x - size.x, position.y + size.y);// x, y

    Vector widthPosition(position.x + size.x, position.y + size.y);// x,y

    Vector upRightPosition(position.x + size.x, position.y - size.y);// x,y

    renderer.drawPoint(position);
    renderer.drawLine(heightPosition, downLeftPosition);
    renderer.drawLine(downLeftPosition, widthPosition);
    renderer.drawLine(widthPosition, upRightPosition);
    renderer.drawLine(upRightPosition, heightPosition);

    if(getContainerChildren()->size() != 0){
        drawChildren(*getContainerChildren());
    }
}