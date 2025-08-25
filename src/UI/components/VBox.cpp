#include "../../include/VBox.hpp"


const int& VBox::getType() const{
    return type;
}

void VBox::setChildrenPosition(){
    std::cout << "vbox setChildrenPosition()" << "\n";
    std::vector<std::unique_ptr<UI>>* children = getContainerChildren(); 

    Vector size = getSize(); 
    int width = size.x; 
    int height = size.y; 

    for(int i = 0; i < children->size(); i++){
	Vector squareOrigin = getSquareOrigin();
	std::cout << "children size: " << children->size() << "\n"; 
	int x = ((width / (children->size()+1) ) * (i+1) ) + squareOrigin.x; 
	int y = (height / 2) + squareOrigin.y;
	Vector newPosition(x, y);   
	children->at(i)->setInnerPosition(newPosition);
	// static_cast<Container*>( children->at(i).get() )->setInnerPosition(childPosition);
    }
}



