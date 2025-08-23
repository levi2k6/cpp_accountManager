#pragma once
#include <memory>
#include "Types.hpp" 
#include "Enums.hpp"
#include "Renderer.hpp"
#include "UI.hpp"
#include "Container.hpp"

class Box : public Container{
    private:
    int type = uiBox;  

    public:
        Box(std::string name);
        Box(std::string name, Vector position, Vector size, Color color, int bevel);

        void onStart() override;
	const int& getType() const override; 

        void drawBorder();
        void addChild(std::unique_ptr<UI> child);

};
