#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "../../include/Container.hpp"
#include "../../include/Renderer.hpp"
#include "../../include/Types.hpp"

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

const int& Container::getType() const{
    return type;
}

void Container::drawUi(){

    Vector position;
    Vector size = getSize();
    Color color = getColor();
    int bevel = getBevel();

    if(getParent() == nullptr){
        position = getPosition();
    }else{
        position = getInnerPosition();
    }

    drawFill(position, size, color, bevel);
    filledCircleRGBA(renderer.getSdlRenderer(), position.x, position.y, 4, 0, 255, 0, 255);

    if(getContainerChildren()->size() != 0){
        drawChildren(*getContainerChildren());
    }
}

void Container::drawFill(Vector &position, Vector &size, Color &color, int &bevel){
     
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

int& Container::getBevel(){
    return bevel;
}

Vector& Container::getSquareOrigin(){
    return squareOrigin;
}

void Container::addChild(std::unique_ptr<UI> child){
    // Vector newPosition = Vector( squareOrigin.x + child->getPosition().x, squareOrigin.y + child->getPosition().y );
    // child->setInnerPosition(newPosition);
    
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



