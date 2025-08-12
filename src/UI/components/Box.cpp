#include <SDL2/SDL.h>
#include "../../include/Box.hpp"
#include "../../include/Types.hpp"

Box::Box(){
    std::cout << "Box created without any arguments." << "\n";
    renderer.changeColor(color);
}

Box::Box(Vector position, Vector size, Color color) : position(position), size(size), color(color){

    this->position = position;
    this->size = size;
    this->color = color;

    renderer.changeColor(this->color);
}

void Box::drawUi(){
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

Vector& Box::getPosition(){
    return position;
}

void Box::setPosition(const int &x, const int &y){
    position.x = x;
    position.y = y;
}

Vector& Box::getSize(){
    return size; 
}

void Box::setSize(const int &x, const int &y){
    size.x = x;
    size.y = y;
}

Color& Box::getColor(){
    return color;
}

void Box::setColor(const uint8_t  &r, const uint8_t  &g, const uint8_t &b, const uint8_t &alpha){
    color.r = r;
    color.g = g;
    color.b = b;
    color.alpha = alpha;
}