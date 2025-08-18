#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include "../../include/Container.hpp"
#include "../../include/Types.hpp"
#include "../../include/Enums.hpp"

Container::Container(std::string name) : UI(name){
    onStart();
}

Container::Container( std::string name, Vector position, Vector size, Color color, int bevel) 
: UI(name, position, size, color), bevel(bevel)
{
    onStart();
}

void Container::onStart(){
}

int& Container::getBevel(){
    return bevel;
}

Vector& Container::getSquareOrigin(){
    return squareOrigin;
}
// int* Container::getUiType(){
//     return &uiType;
// }

void Container::addChild(std::unique_ptr<UI> child){
    child->setParent(this);
    Vector newPosition = Vector( squareOrigin.x + child->getPosition().x, squareOrigin.y + child->getPosition().y );
    std::cout << "square origin here: " << child->getName() << "\n";
    child->setInnerPosition(newPosition);
    std::cout << "new child position: " << "\n";
    child->getPosition().print();
    
    uiChildren.push_back(std::move(child));
}

std::vector<std::unique_ptr<UI>>* Container::getContainerChildren(){
    return &uiChildren;
}

void Container::drawChildren(std::vector<std::unique_ptr<UI>> &children){
    for(auto &child : children){
        child->drawUi();
        if( Container* castedChild = dynamic_cast<Container*>(child.get())){
            castedChild->drawChildren(*castedChild->getContainerChildren()); 
        }
    }
}