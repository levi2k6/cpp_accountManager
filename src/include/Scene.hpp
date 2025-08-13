#pragma once
#include <iostream>
#include <vector> 
#include "UI.hpp"

class Scene{

    public:
        virtual void drawScene(){};
        virtual ~Scene(){}
};
