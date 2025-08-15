#include <iostream>
#include <yaml-cpp/yaml.h>
#include "../include/Box.hpp"
#include "../include/UILayoutSystem.hpp"
#include "../include/Types.hpp"

void UILayoutSystem::createUiElements(YAML::Node data, std::vector<std::unique_ptr<UI>>* sceneArrayUis){
        int i = 0;

        for(const auto& uiData: data){
            std::cout << "number: " << i << "\n";

            if(uiData["type"].as<std::string>() == "Box"){
                Vector position(uiData["position"]["x"].as<int>(), uiData["position"]["y"].as<int>());
                Vector size(uiData["size"]["x"].as<int>(), uiData["size"]["y"].as<int>());
                uint8_t colorR = uiData["color"]["r"].as<uint8_t>();
                uint8_t colorG = uiData["color"]["g"].as<uint8_t>();
                uint8_t colorB = uiData["color"]["b"].as<uint8_t>();
                uint8_t alpha = uiData["color"]["alpha"].as<uint8_t>();
                Color color(colorR, colorG, colorB, alpha);

                sceneArrayUis->push_back(std::move(createBox(uiData["name"].as<std::string>(), position, size, color)));
                std::cout << (*sceneArrayUis)[i]->getName() << "\n";
            }else if(uiData["type"].as<std::string>() == "Button"){
            }
            i++;
        }
}

std::unique_ptr<UI> UILayoutSystem::createBox(std::string name, Vector position, Vector size, Color color){
    std::unique_ptr<UI> box = std::make_unique<Box>(name, position, size, color);
    return std::move(box);
}

void UILayoutSystem::createButton(std::string name, Vector position, Vector size, Color color){
    std::cout << "button created" << "\n";
}


UILayoutSystem uiLayoutSystem;  