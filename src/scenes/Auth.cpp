#include <iostream>
#include <memory>
#include "../include/Auth.hpp"
#include "../include/Box.hpp"
#include "../include/Types.hpp"


void  Auth::initAuth(){

    Vector position1(100, 100); 
    Vector size1(50, 50);
    Color color1(255, 0, 0, 255);
    Box box1 = Box(position1, size1, color1); 


    Box box2 = Box();
    box2.setSize(50, 50);
    box2.setColor(0, 244, 0, 255);

    Box box3 = Box();
    box2.getColor().r = 100;

    uis[0] = box1;
    uis[1] = box2;
    uis[2] = box3;
}

void Auth::drawScene(){
    for(int i = 0; i < uis.size(); i++){
        uis[i].drawUi();
    }
}

Auth auth = Auth();
