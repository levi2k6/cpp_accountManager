#include "../include/SceneSystem.hpp" 

std::string SceneSystem::getCurrentScene(){
    return currentScene; 
};

void SceneSystem::setCurrentScene(std::string scene){
    currentScene = scene;
}

void SceneSystem::sceneChanger(){
    if(currentScene == "main"){
        std::cout << "you are main" << "\n";
    }else if(currentScene == "island"){
        std::cout << "you are in an island." << "\n";
    }
}
