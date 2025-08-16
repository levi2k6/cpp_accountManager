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
            if(!child["children"].IsNull()){
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
    
    std::unique_ptr<UI> box = std::make_unique<Box>(name, position, size, color);
    return std::move(box);
}

void UILayoutSystem::initUi(Container container){
    // if(uiData["children"].IsNull()){
    //     for(const auto& child : uiData["children"]){
    //         if( Box* box = dynamic_cast<Box*>((*sceneArrayUis)[i].get()) ){
    //             std::unique_ptr<UI> childBox = createBox(
    //                 child["name"].as<std::string>(""),
    //                 child["position"]["x"].as<int>(0),
    //                 child["position"]["y"].as<int>(0),
    //                 child["size"]["x"].as<int>(50),
    //                 child["size"]["y"].as<int>(50),
    //                 child["color"]["r"].as<uint8_t>(255),
    //                 child["color"]["g"].as<uint8_t>(255),
    //                 child["color"]["b"].as<uint8_t>(255),
    //                 child["color"]["alpha"].as<uint8_t>(255)
    //             );
    //             box->addChild(std::move(childBox));
    //         };
    //     }
    // }
}


// void UILayoutSystem::createButton(std::string name, Vector position, Vector size, Color color){
//     std::cout << "button created" << "\n";
// }


UILayoutSystem uiLayoutSystem;  