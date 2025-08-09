#include "../../include/UISystem.hpp"
#include "../../include/Renderer.hpp"
#include "../../include/Types.hpp"


void UISystem::drawLine(const Vector& start, const Vector& end){
    SDL_RenderDrawLine(renderer.getSdlRenderer(), start.x, start.y, end.x, end.y);
}

void UISystem::drawPoint(const Vector& position ){

    SDL_RenderDrawPoint(renderer.getSdlRenderer(), position.x, position.y);
    
}

void drawCircle(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;   // Decision criterion divided by 2 evaluated at x=r, y=0

    while (y <= x) {
        // Draw the eight octants
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX + y, centerY + x);
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX - x, centerY + y);
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX - y, centerY + x);
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX - x, centerY - y);
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX - y, centerY - x);
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX + x, centerY - y);
        SDL_RenderDrawPoint(renderer.getSdlRenderer(),  centerX + y, centerY - x);
        y++;
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;  // Change for y -> y+1, x -> x-1
        }
    }
}

void UISystem::createBox(const Vector& position , const Vector& size){

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

    // drawPoint(heightPosition1);
    // drawPoint(widthPosition1);
    drawLine(heightPosition, downLeftPosition);
    drawLine(downLeftPosition, widthPosition);
    drawLine(widthPosition, upRightPosition);
    drawLine(upRightPosition, heightPosition);
    // drawLine(color, )
    // drawLine(color, widthPosition, upRightPosition);
} 


UISystem uiSystem = UISystem(); 


