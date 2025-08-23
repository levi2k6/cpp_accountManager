#pragma once
#include <memory>
#include <any>
#include <yaml-cpp/yaml.h>
#include "UI.hpp"
#include "Container.hpp"

class UILayoutSystem{

    private:

    public:
        UILayoutSystem(){};
        void loadUiData(Container *sceneRoot, YAML::Node data);
	void initializePositionUis(std::vector<std::unique_ptr<UI>>* rootUi);
        void initRootChildren(UI *parent, YAML::Node children);    
	std::unordered_map<std::string, std::any> constructSquare(YAML::Node uiData); 
        std::unique_ptr<UI> createBox(YAML::Node uiData);
	std::unique_ptr<UI> createVBox(YAML::Node uiData);
};

extern UILayoutSystem uiLayoutSystem;
