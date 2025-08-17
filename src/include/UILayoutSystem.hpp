#pragma once
#include <iostream>
#include <memory>
#include <yaml-cpp/yaml.h>
#include "UI.hpp"
#include "Container.hpp"

class UILayoutSystem{

    private:

    public:
        UILayoutSystem(){};
        void loadUiData(Container *sceneRoot, YAML::Node data);
        void initRootChildren(UI *parent, YAML::Node children);    
        std::unique_ptr<UI> createBox(YAML::Node uiData);
};

extern UILayoutSystem uiLayoutSystem;
