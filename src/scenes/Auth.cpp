#include <iostream>
#include <memory>
#include "../include/Auth.hpp"
#include "../include/Box.hpp"
#include "../include/Types.hpp"


void  Auth::initAuth(){
    std::cout << "auth Initialized" << "\n";

    Vector position1(100, 100); 
    Vector size1(50, 50);
    Color color1(255, 0, 0, 255);
    std::unique_ptr<Box> box1 = std::make_unique<Box>(std::string("box1"), position1, size1, color1); 

    std::unique_ptr<Box> box2 = std::make_unique<Box>(std::string("box2"));
    box2->setSize(50, 50);
    box2->setColor(0, 244, 0, 255);

    std::unique_ptr<Box> box3 = std::make_unique<Box>(std::string("box3"));
    box2->getColor().r = 100;

    uis[0] = std::move(box1);
    uis[1] = std::move(box2);
    uis[2] = std::move(box3);
}

void Auth::drawScene(){
    // std::cout << "draw scene" << "\n";
    for(int i = 0; i < 3; i++){
        uis[i]->drawUi();
        // std::cout << "name: " << uis[i]->getName() << "\n";
    }
}

Auth auth = Auth();
