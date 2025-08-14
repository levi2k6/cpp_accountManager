#include <SDL2/SDL.h>
#include "../../include/Box.hpp"
#include "../../include/Types.hpp"

Box::Box(std::string name) : UI(name){
    onStart();
}

Box::Box( std::string name, Vector position, Vector size, Color color) : UI(name, position, size, color){
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

    if(children.size() != 0){
        drawChildren();
    }
}

void Box::addChild(std::unique_ptr<UI> child){

    Vector newPosition = Vector( boxOrigin.x + child->getPosition().x, boxOrigin.y + child->getPosition().y );
    child->setInnerPosition(newPosition.x, newPosition.y);
    children.push_back(std::move(child));
}

void Box::drawChildren(){
    for(int i = 0; i < children.size(); i++){
        children[i]->drawUi();
        // std::cout << children[i]->getName() << "\n";
        // std::cout << "name: " << children[i]->getName() << "\n";
        // std::cout << "position: " << children[i]->getPosition().x << " | " << children[i]->getPosition().y << "\n";
        // std::cout << "size: " << children[i]->getSize().x << " | " << children[i]->getSize().y << "\n";
    }
}