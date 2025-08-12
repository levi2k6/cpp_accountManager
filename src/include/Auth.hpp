#include <iostream>
#include <array>
#include <memory>
#include "Scene.hpp" 
#include "Box.hpp"

class Auth : public Scene{

    private:
        std::array<Box, 100> uis;

    public:
        void drawScene() override;
        void initAuth();
};

extern Auth auth;
