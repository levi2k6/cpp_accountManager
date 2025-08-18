#include <iostream>
#include <yaml-cpp/yaml.h>
#include "../include/Box.hpp"
#include "../include/UILayoutSystem.hpp"
#include "../include/Types.hpp"


void UILayoutSystem::loadUiData(Container *parent, YAML::Node children){
    if(children.IsNull()){
        std::cout << "UI children data is empty";
        return;
    }

    for(const auto& child : children){

        if(child["type"].as<std::string>() == "Box"){
            std::unique_ptr<UI> newBox = createBox(child);
            std::cout << "name: " << newBox->getName() << "\n";
            std::cout << "size: ";
            newBox->getSize().print();

            if(child["children"]){
                loadUiData(static_cast<Container*>(newBox.get()), child["children"]);
            }
            parent->addChild(std::move(newBox));
        }

    }

}

std::unique_ptr<UI> UILayoutSystem::createBox(YAML::Node uiData){

    std::string name = uiData["name"].as<std::string>("");
    Vector position(
        uiData["position"]["x"].as<int>(0),
        uiData["position"]["y"].as<int>(0)
    );
    Vector size(
        uiData["size"]["x"].as<int>(50),
        uiData["size"]["y"].as<int>(50)
    );
    Color color(
        uiData["color"]["r"].as<uint8_t>(255),
        uiData["color"]["g"].as<uint8_t>(255),
        uiData["color"]["b"].as<uint8_t>(255),
        uiData["color"]["alpha"].as<uint8_t>(255)
    );

    int bevel = uiData["bevel"].as<int>(0);

    std::unique_ptr<UI> box = std::make_unique<Box>(name, position, size, color, bevel);
    return std::move(box);
}


UILayoutSystem uiLayoutSystem;  