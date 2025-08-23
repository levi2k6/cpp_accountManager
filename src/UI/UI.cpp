#include <iostream>
#include <memory>
#include "../include/UI.hpp"
#include "../include/Renderer.hpp"
#include "../include/Types.hpp"

UI::UI(std::string name){
    this->name = name;
}

UI::UI(std::string name, Vector position, Vector size, Color color){
    this->name = name;
    this->position = position;
    this->size = size;
    this->color = color;
};

std::string UI::getName(){
    return name;
}

void UI::setName(std::string name){
    this->name = name; 
}

UI* UI::getParent(){
    return parent;
};

void UI::setParent(UI *parent){
    this->parent = parent;
}

Vector& UI::getInnerPosition(){
    return innerPosition;
}

void UI::setInnerPosition(Vector &position){
    innerPosition = position;
}

Vector& UI::getPosition(){
    return position;
}

void UI::setPosition(Vector &position){
    this->position = position;
}


Vector& UI::getSize(){
    return size; 
}

void UI::setSize(const int &x, const int &y){
    size.x = x;
    size.y = y;
}

Color& UI::getColor(){
    return color;
}

void UI::setColor(const uint8_t  &r, const uint8_t  &g, const uint8_t &b, const uint8_t &alpha){
    color.r = r;
    color.g = g;
    color.b = b;
    color.alpha = alpha;
}

const int& UI::getType() const{
    return type;
}

