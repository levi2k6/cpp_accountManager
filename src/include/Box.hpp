#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include "Types.hpp" 
#include "Renderer.hpp"
#include "UI.hpp"


class Box : public UI{
    private:

        std::vector<std::unique_ptr<UI>> children;

    public:
        Box(std::string name);
        Box(std::string name, Vector position, Vector size, Color color);
        void onStart() override;
        void drawUi() override;
};
