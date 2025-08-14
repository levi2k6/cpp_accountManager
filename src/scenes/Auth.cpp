#include <iostream>
#include <memory>
#include "../include/WindowDisplay.hpp"
#include "../include/Auth.hpp"
#include "../include/Box.hpp"
#include "../include/Types.hpp"


void  Auth::initAuth(){
    std::cout << "auth Initialized" << "\n";

    Vector windowSize = windowDisplay.getSize();

    Vector position1 = Vector(windowSize.x / 2, windowSize.y / 2);
    Vector size1 = Vector(200, 200);
    Color color1(255, 0, 0, 255);
    std::unique_ptr<Box> box1 = std::make_unique<Box>(std::string("box1"), position1, size1, color1); 

    std::unique_ptr<UI> boxChild = std::make_unique<Box>("boxChild");
    boxChild->setPosition(50, 50);
    boxChild->setSize(30, 30);
    boxChild->setColor(255, 255, 255, 255);

    box1->addChild(std::move(boxChild));

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
        // std::cout << "position: " << uis[i]->getPosition().x << " | " << uis[i]->getPosition().y << "\n";
        // std::cout << "size: " << uis[i]->getSize().x << " | " << uis[i]->getSize().y << "\n";
    }
}

Auth auth = Auth();
