#pragma once
#include "Types.hpp" 
#include "UISystem.hpp"
#include "Renderer.hpp"


class Box{

    private:
        Vector position; 
        Vector size;
        Color color;


    public:
        Box(Vector position, Vector size, Color color) : position(position), size(size), color(color){

            renderer.changeColor(color);
            createBox(position, size);
            
        }

        void createBox(const Vector& position , const Vector& size){

            Vector heightPosition; 
            heightPosition.x = position.x - size.x;
            heightPosition.y = position.y - size.y;

            Vector downLeftPosition; 
            downLeftPosition.x = position.x - size.x;
            downLeftPosition.y = position.y + size.y;

            Vector widthPosition;
            widthPosition.x = position.x + size.x;
            widthPosition.y = position.y + size.y;

            Vector upRightPosition;
            upRightPosition.x = position.x + size.x;
            upRightPosition.y = position.y - size.y; 

            uiSystem.drawPoint(position);
            uiSystem.drawLine(heightPosition, downLeftPosition);
            uiSystem.drawLine(downLeftPosition, widthPosition);
            uiSystem.drawLine(widthPosition, upRightPosition);
            uiSystem.drawLine(upRightPosition, heightPosition);
            // drawLine(color, )
            // drawLine(color, widthPosition, upRightPosition);
        } 
};
