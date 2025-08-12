#include "../include/SceneSystem.hpp" 
#include "../include/Auth.hpp"

std::string SceneSystem::getCurrentScene(){
    return currentScene; 
};

void SceneSystem::setCurrentScene(std::string scene){
    currentScene = scene;
}

void SceneSystem::sceneChanger(){

    std::cout << "scene checker" << "\n";
    if(currentScene == "main"){
        std::cout << "you are main" << "\n";
        auth.drawScene();

    }else if(currentScene == "island"){
        std::cout << "you are in an island." << "\n";
    }
}

SceneSystem sceneSystem = SceneSystem(); 
