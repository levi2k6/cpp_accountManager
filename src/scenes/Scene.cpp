#include <yaml-cpp/yaml.h>

#include "../include/Scene.hpp"
#include "../include/Box.hpp"
#include "../include/UILayoutSystem.hpp"


Scene::Scene(std::string layoutLocation) : layoutLocation(layoutLocation){}

void Scene::initScene(){

    YAML::Node yamlData = YAML::LoadFile(layoutLocation);
    auto data = yamlData["data"];

    uiLayoutSystem.loadUiData(getRootUi(), data);

}

Box* Scene::getRootUi(){
    return rootUi.get(); 
}

void Scene::setRootUi(std::unique_ptr<Box> box){
    rootUi = std::move(box);
}


