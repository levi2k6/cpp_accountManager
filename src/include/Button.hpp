#pragma once
#include "../include/UI.hpp"
#include "../include/Types.hpp"

class Button : UI{

    private:

    public:
        Button(std::string name);
        Button(std::string name, Vector position, Vector size, Color color);
        void onStart() override;
        void drawUi() override;
        
};