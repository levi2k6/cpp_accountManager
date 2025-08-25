#include <yaml-cpp/yaml.h>
#include "../include/Scene.hpp"
#include "../include/Container.hpp"
#include "../include/Box.hpp"
#include "../include/UILayoutSystem.hpp"

Scene::Scene(std::unique_ptr<Box> rootUi, std::string layoutLocation) : rootUi(std::move(rootUi)), layoutLocation(layoutLocation){}

void Scene::initScene(){
    rootUi->getContainerChildren()->clear();

    YAML::Node yamlData = YAML::LoadFile(layoutLocation);

    uiLayoutSystem.loadUiData(rootUi.get(), yamlData);
    rootUi->setChildrenPosition();
    uiLayoutSystem.initializePositionUis(rootUi->getContainerChildren());
}

Box* Scene::getRootUi(){
    return rootUi.get(); 
}

void Scene::setRootUi(std::unique_ptr<Box> container){
    rootUi = std::move(container);
}

void Scene::drawScene(){
    std::vector<std::unique_ptr<UI>> *rootChildren = rootUi->getContainerChildren();
    rootUi->drawChildren(*rootChildren);
}


