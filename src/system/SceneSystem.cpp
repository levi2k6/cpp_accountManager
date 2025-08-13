#include "../include/SceneSystem.hpp" 
#include "../include/Auth.hpp"
#include "../include/Box.hpp"

std::string SceneSystem::getCurrentScene(){
    return currentScene; 
};

void SceneSystem::setCurrentScene(std::string scene){
    currentScene = scene;
}

Box boxMain("boxMain");

void SceneSystem::sceneChanger(){

    // std::cout << "scene checker" << "\n";
    if(currentScene == "main"){
        // std::cout << "you are main" << "\n";

        boxMain.drawUi();

        auth.drawScene();

    }else if(currentScene == "island"){
        std::cout << "you are in an island." << "\n";
    }
}

SceneSystem sceneSystem = SceneSystem(); 
