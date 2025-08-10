#include <SDL2/SDL.h> 
#include "../include/Renderer.hpp"
#include "../include/WindowDisplay.hpp"
#include "../include/Types.hpp"


void Renderer::initRenderer(){

    sdlRenderer = SDL_CreateRenderer(windowDisplay.getWindow(), -1 ,SDL_RENDERER_ACCELERATED);

}

SDL_Renderer* Renderer::getSdlRenderer(){

    return sdlRenderer;

}

void Renderer::changeColor(const Color &color){
    SDL_SetRenderDrawColor(sdlRenderer, color.r, color.g, color.b, color.alpha);
}



void Renderer::drawLine(const Vector& start, const Vector& end){
    SDL_RenderDrawLine(sdlRenderer, start.x, start.y, end.x, end.y);
}

void Renderer::drawPoint(const Vector& position ){

    SDL_RenderDrawPoint(sdlRenderer, position.x, position.y);
    
}

void Renderer::drawCircle(int centerX, int centerY, int radius) {
    int x = radius;
    int y = 0;
    int decisionOver2 = 1 - x;   // Decision criterion divided by 2 evaluated at x=r, y=0

    while (y <= x) {
        SDL_RenderDrawPoint(sdlRenderer,  centerX + x, centerY + y);
        SDL_RenderDrawPoint(sdlRenderer,  centerX + y, centerY + x);
        SDL_RenderDrawPoint(sdlRenderer,  centerX - x, centerY + y);
        SDL_RenderDrawPoint(sdlRenderer,  centerX - y, centerY + x);
        SDL_RenderDrawPoint(sdlRenderer,  centerX - x, centerY - y);
        SDL_RenderDrawPoint(sdlRenderer,  centerX - y, centerY - x);
        SDL_RenderDrawPoint(sdlRenderer,  centerX + x, centerY - y);
        SDL_RenderDrawPoint(sdlRenderer,  centerX + y, centerY - x);
        y++;
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;   // Change in decision criterion for y -> y+1
        } else {
            x--;
            decisionOver2 += 2 * (y - x) + 1;  // Change for y -> y+1, x -> x-1
        }
    }
}

void Renderer::createBox(const Vector& position , const Vector& size){

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


Renderer renderer = Renderer();
