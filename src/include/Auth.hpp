#pragma once
#include <iostream>
#include <array>
#include <memory>
#include "Scene.hpp" 
#include "Box.hpp"
#include "Container.hpp"


class Auth : public Scene{

    private:

    public:
        Auth(std::unique_ptr<Container> rootUi, std::string layoutLocation) : Scene(std::move(rootUi), layoutLocation){}
        void initAuth();
        Box* getUis();
        
        void setRootUi(std::unique_ptr<UI> ui);
};

extern Auth auth;
