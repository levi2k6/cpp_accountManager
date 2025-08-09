#include <SDL2/SDL.h> 
#include "../include/Renderer.hpp"
#include "../include/WindowDisplay.hpp"



void Renderer::initRenderer(){

    sdlRenderer = SDL_CreateRenderer(windowDisplay.getWindow(), -1 ,SDL_RENDERER_ACCELERATED);

}

SDL_Renderer* Renderer::getSdlRenderer(){

    return sdlRenderer;

}

void Renderer::changeColor(const Color &color){
    SDL_SetRenderDrawColor(renderer.getSdlRenderer(), color.r, color.g, color.b, color.alpha);
}

Renderer renderer = Renderer();
