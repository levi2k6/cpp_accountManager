#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include "../../include/Container.hpp"
#include "../../include/Types.hpp"
#include "../../include/Enums.hpp"

Container::Container(std::string name) : UI(name){
    onStart();
}

Container::Container( std::string name, Vector position, Vector size, Color color) : UI(name, position, size, color){
    onStart();
}

void Container::onStart(){
}

int* Container::getUiType(){
    return &uiType;
}

void Container::addChild(std::unique_ptr<UI> child){
    child->setParent(this);
    Vector newPosition = Vector( squareOrigin.x + child->getPosition().x, squareOrigin.y + child->getPosition().y );
    child->setInnerPosition(newPosition.x, newPosition.y);
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