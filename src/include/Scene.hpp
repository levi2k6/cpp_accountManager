#pragma once
#include <iostream>
#include <vector> 
#include "UI.hpp"

class Container;

class Scene{
    private:
        std::string layoutLocation = "";
        std::unique_ptr<Container> rootUi;

    public:
        Scene(std::unique_ptr<Container> rootUi, std::string layoutLocation);
        void initScene();
        Container* getRootUi();
        void setRootUi(std::unique_ptr<Container> ui);
        virtual void drawScene();
        virtual ~Scene(){}
};
