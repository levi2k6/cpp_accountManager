#pragma once
#include <iostream>
#include <memory>
#include <yaml-cpp/yaml.h>
#include "UI.hpp"

class UILayoutSystem{

    private:

    public:
        UILayoutSystem(){};
        void createUiElements(YAML::Node data, std::vector<std::unique_ptr<UI>>*);
        std::unique_ptr<UI> createBox(std::string name, Vector position, Vector size, Color color);
        void createButton(std::string name, Vector position, Vector size, Color color);
};

extern UILayoutSystem uiLayoutSystem;
