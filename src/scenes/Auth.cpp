#include <iostream>
#include <memory>
#include <yaml-cpp/yaml.h>
#include "../include/Auth.hpp"
#include "../include/WindowDisplay.hpp"
#include "../include/UILayoutSystem.hpp"
#include "../include/UI.hpp"
#include "../include/Container.hpp"
#include "../include/Box.hpp"
#include "../include/Types.hpp"

void  Auth::initAuth(){
    std::cout << "Auth create" << "\n";
}

std::unique_ptr<Box> authBox = std::make_unique<Box>("authBox");
Auth auth(std::move(authBox), "../src/layouts/AuthLayout.yaml");
