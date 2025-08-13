#include <SDL2/SDL.h>
#include "../../include/Button.hpp"
#include "../../include/Renderer.hpp"

Button::Button(std::string name) : UI(name){
    onStart();
};

Button::Button(std::string name, Vector position, Vector size, Color color) : UI(name, position, size, color){
    onStart();
}

void Button::onStart(){
    std::cout << "Button created" << "\n";
}

void Button::drawUi(){
    Vector position = getPosition();
    Vector size = getSize();
    Color color = getColor();

    renderer.changeColor(color);

    Vector heightPosition(position.x - size.x, position.y - size.y);// x, y

    Vector downLeftPosition(position.x - size.x, position.y + size.y);// x, y

    Vector widthPosition(position.x + size.x, position.y + size.y);// x,y

    Vector upRightPosition(position.x + size.x, position.y - size.y);// x,y

    renderer.drawPoint(position);
    renderer.drawLine(heightPosition, downLeftPosition);
    renderer.drawLine(downLeftPosition, widthPosition);
    renderer.drawLine(widthPosition, upRightPosition);
    renderer.drawLine(upRightPosition, heightPosition);
}



