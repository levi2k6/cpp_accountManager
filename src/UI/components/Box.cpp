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

const int& Box::getType() const{
    return type;
}

void Box::setChildrenPosition(){

    std::cout << "parent: " << getName() << "\n";
    std::cout << "x: " << getPosition().x << "\n";
    std::cout << "y: " << getPosition().y << "\n";


    std::cout << "box setChildrenPosition()" << "\n";
    std::cout << "updated here bro look at here" << "\n";
    std::vector<std::unique_ptr<UI>>* children = getContainerChildren(); 

    for(auto& child : *children){

	std::cout << "child: " << child->getName() << "\n";
	std::cout << "x: " << child->getPosition().x << "\n";
	std::cout << "y: " << child->getPosition().y << "\n";
	
	Vector newPosition = Vector( getSquareOrigin().x + child->getPosition().x, getSquareOrigin().y + child->getPosition().y );
	child->setInnerPosition(newPosition);
    }
}

