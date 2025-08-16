#pragma once
#include <iostream>
#include <array>
#include <memory>
#include "Scene.hpp" 
#include "Box.hpp"

class Auth : public Scene{

    private:
        std::unique_ptr<Box> rootUi;

    public:
        void initAuth();
        Box* getUis();
        
        void setRootUi(std::unique_ptr<UI> ui);
        void drawScene() override;
};

extern Auth auth;
