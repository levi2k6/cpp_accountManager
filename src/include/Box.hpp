#pragma once
#include <iostream>
#include <memory>
#include <vector>
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
        void drawUi() override;
        void drawBorder();
        void drawFill(Vector &position, Vector &size, Color &color, int &bevel);
        void addChild(std::unique_ptr<UI> child);
};
