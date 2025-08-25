#pragma once
#include <iostream>
#include <memory>

class Box;

class Scene{
    private:
        std::string layoutLocation = "";
        std::unique_ptr<Box> rootUi;

    public:
        Scene(std::unique_ptr<Box> rootUi, std::string layoutLocation);
        void initScene();
        Box* getRootUi();
        void setRootUi(std::unique_ptr<Box> ui);
        void drawScene();
        virtual ~Scene(){}
};
