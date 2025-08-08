#include "../include/UISystem.hpp"
#include "../include/Renderer.hpp"
#include "../include/Types.hpp"


void UISystem::drawLine(const Color& color, const Vector& start, const Vector& end){
    SDL_SetRenderDrawColor(renderer.getSdlRenderer(), color.r, color.g, color.b, color.alpha);
    SDL_RenderDrawLine(renderer.getSdlRenderer(), start.x, start.y, end.x, end.y);
}


UISystem uiSystem = UISystem(); 