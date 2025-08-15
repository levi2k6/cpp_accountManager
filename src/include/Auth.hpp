#pragma once
#include <iostream>
#include <array>
#include <memory>
#include "Scene.hpp" 
#include "Box.hpp"

class Auth : public Scene{

    private:
        std::vector<std::unique_ptr<UI>> uis;

    public:
        void initAuth();
        std::vector<std::unique_ptr<UI>>* getUis();
        
        void addUis(std::unique_ptr<UI> ui);
        void drawScene() override;
};

extern Auth auth;
