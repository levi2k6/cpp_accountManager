#pragma once
#include <memory>
#include "Types.hpp" 
#include "Renderer.hpp"
#include "UI.hpp"
#include "Container.hpp"

class Box : public Container{
    private:

    public:
        Box(std::string name);
        Box(std::string name, Vector position, Vector size, Color color, int bevel);
        void onStart() override;
        void drawBorder();
        void addChild(std::unique_ptr<UI> child);
};
