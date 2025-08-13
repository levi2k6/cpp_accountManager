#pragma once
#include <iostream>
#include <array>
#include <memory>
#include "Scene.hpp" 
#include "Box.hpp"

class Auth : public Scene{

    private:
        std::array<std::unique_ptr<UI>, 100> uis;

    public:
        void drawScene() override;
        void initAuth();
};

extern Auth auth;
