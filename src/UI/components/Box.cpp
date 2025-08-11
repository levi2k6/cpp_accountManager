#include <SDL2/SDL.h>
#include "../../include/Box.hpp"
#include "../../include/Types.hpp"


Box::Box(Vector position, Vector size, Color color) : position(position), size(size), color(color){

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
