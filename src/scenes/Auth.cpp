#include <iostream>
#include <memory>
#include <yaml-cpp/yaml.h>
#include "../include/Auth.hpp"
#include "../include/WindowDisplay.hpp"
#include "../include/UILayoutSystem.hpp"
#include "../include/UI.hpp"
#include "../include/Box.hpp"
#include "../include/Types.hpp"


void  Auth::initAuth(){
    if(size() != 0){
        uis.clear();
    }
    YAML::Node yamlData = YAML::LoadFile("../src/layouts/AuthLayout.yaml");
    auto data = yamlData["data"];

    uiLayoutSystem.createUiElements(data, &uis);
}

std::vector<std::unique_ptr<UI>>* Auth::getUis(){
    return &uis; 
}

void Auth::addUis(std::unique_ptr<UI> ui){
    uis.push_back(std::move(ui));
}

void Auth::drawScene(){
    // std::cout << uis.size() << "\n";

    for(int i = 0; i < uis.size(); i++){
        uis[i]->drawUi();
        // std::cout << "name: " << uis[i]->getName() << "\n";
        // std::cout << "position: " << uis[i]->getPosition().x << " | " << uis[i]->getPosition().y << "\n";
        // std::cout << "size: " << uis[i]->getSize().x << " | " << uis[i]->getSize().y << "\n";
    }
}

Auth auth = Auth();
