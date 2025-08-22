#include <iostream>
#include <any>
#include <yaml-cpp/yaml.h>
#include "../include/Box.hpp"
#include "../include/VBox.hpp"
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
        }else if(child["type"].as<std::string>() == "VBox"){
	    std::unique_ptr<UI> newVBox = createVBox(child);

	    if(child["children"]){
		loadUiData(static_cast<Container*>(newVBox.get()), child["children"]);
	    }

	    parent->addChild(std::move(newVBox));
	}
    }
}

std::unordered_map<std::string, std::any> UILayoutSystem::constructSquare(YAML::Node uiData){
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

    std::unordered_map<std::string, std::any> data; 
    data["position"] = position;
    data["size"] = size;
    data["color"] = color;
    return data;
}

std::unique_ptr<UI> UILayoutSystem::createBox(YAML::Node uiData){

    std::string name = uiData["name"].as<std::string>("");

    std::unordered_map<std::string, std::any> squareData = constructSquare(uiData); 
    
    int bevel = uiData["bevel"].as<int>(0);

    std::unique_ptr<UI> box = std::make_unique<Box>(
	name,
        std::any_cast<Vector>(squareData["position"]),
	std::any_cast<Vector>(squareData["size"]),
	std::any_cast<Color>(squareData["color"]),
	bevel
    );

    return std::move(box);
}

std::unique_ptr<UI> UILayoutSystem::createVBox(YAML::Node uiData){
    std::string name = uiData["name"].as<std::string>("");

    std::unordered_map<std::string, std::any> squareData = constructSquare(uiData); 
    
    int bevel = uiData["bevel"].as<int>(0);

    std::unique_ptr<UI> box = std::make_unique<VBox>(
	name,
        std::any_cast<Vector>(squareData["position"]),
	std::any_cast<Vector>(squareData["size"]),
	std::any_cast<Color>(squareData["color"]),
	bevel
    );

    return std::move(box);

}

UILayoutSystem uiLayoutSystem;  
