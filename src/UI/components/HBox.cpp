#include "../../include/HBox.hpp"

const int& HBox::getType() const{
    return type;
}

void HBox::setChildrenPosition(){
    std::cout << "hbox setChildrenPosition()" << "\n";
    std::vector<std::unique_ptr<UI>>* children = getContainerChildren(); 

    Vector size = getSize(); 
    int width = size.x; 
    int height = size.y; 

    for(int i = 0; i < children->size(); i++){
	Vector squareOrigin = getSquareOrigin();
	std::cout << "children size: " << children->size() << "\n"; 
	int x = (width / 2) + squareOrigin.x; 
	int y = ((height / (children->size()+1) ) * (i+2) ) + squareOrigin.y;
	Vector newPosition(x, y);   
	children->at(i)->setInnerPosition(newPosition);
    }
}  


