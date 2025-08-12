#include<iostream>


class SceneSystem{

    private:
        std::string currentScene = "main";

    public:
        std::string getCurrentScene();
        void setCurrentScene(std::string scene);
        void sceneChanger();
};

extern SceneSystem sceneSystem;

