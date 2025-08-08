#include <SDL2/SDL.h> 
#include "../include/Renderer.hpp"
#include "../include/WindowDisplay.hpp"



void Renderer::initRenderer(){

    sdlRenderer = SDL_CreateRenderer(windowDisplay.getWindow(), -1 ,SDL_RENDERER_ACCELERATED);

}

SDL_Renderer* Renderer::getSdlRenderer(){

    return sdlRenderer;

}

Renderer renderer = Renderer();
