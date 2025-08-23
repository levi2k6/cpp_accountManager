#include "../../include/VBox.hpp"


const int& VBox::getType() const{
    return type;
}

void VBox::setChildrenPosition(){

    std::vector<std::unique_ptr<UI>>* children = getContainerChildren(); 

    Vector position = getPosition(); 
    int width = position.x; 
    int height = position.y; 

    for(int i = 0; i < children->size(); i++){
	int x = (width / children->size()) * i+1; 
	int y = height / 2;
	Vector childPosition(x, y);   
	setInnerPosition(childPosition);
	// static_cast<Container*>( children->at(i).get() )->setInnerPosition(childPosition);
    }
}



