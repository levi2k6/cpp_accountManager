#include <iostream>
#include <yaml-cpp/yaml.h>
#include "../include/Scene.hpp"
#include "../include/Container.hpp"
#include "../include/Box.hpp"
#include "../include/UILayoutSystem.hpp"


Scene::Scene(std::unique_ptr<Container> rootUi, std::string layoutLocation) : rootUi(std::move(rootUi)), layoutLocation(layoutLocation){}

void Scene::initScene(){

    YAML::Node yamlData = YAML::LoadFile(layoutLocation);
    auto data = yamlData["data"];

    uiLayoutSystem.loadUiData(rootUi.get(), data);
}

Container* Scene::getRootUi(){
    return rootUi.get(); 
}

void Scene::setRootUi(std::unique_ptr<Container> container){
    rootUi = std::move(container);
}

void Scene::drawScene(){
    std::vector<std::unique_ptr<UI>> *rootContainer = rootUi->getContainerChildren();
    rootUi->drawChildren(*rootContainer);
}


