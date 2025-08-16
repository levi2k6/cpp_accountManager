#pragma once
#include <iostream>
#include <vector> 
#include "UI.hpp"

class Scene{
    private:
        std::string layoutLocation = "";
        std::unique_ptr<Box> rootUi;

    public:
        Scene(std::string layoutLocation);
        void initScene();
        Box* getRootUi();
        void setRootUi(std::unique_ptr<Box> ui);
        virtual void drawScene(){};
        virtual ~Scene(){}
};
