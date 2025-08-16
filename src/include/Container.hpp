#pragma once 
#include <iostream>
#include <vector>
#include <memory>
#include "UI.hpp"
#include "Types.hpp"


class Container : public UI {
    private:
        std::vector<std::unique_ptr<UI>> uiChildren;

    public:
        Container(std::string name) : UI(name){}
        Container(std::string name, Vector position, Vector size, Color color) : UI(name, position, size, color){}
        // ~Container() noexcept override = default;
        void onStart();
        void drawUi();
        void addChild(std::unique_ptr<UI> child);
        void drawChildren();
};