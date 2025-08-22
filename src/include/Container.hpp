#pragma once 
#include <vector>
#include <memory>
#include "UI.hpp"
#include "Types.hpp"

class Container : public UI {
    private:

        int bevel;
        Vector squareOrigin = Vector( getPosition().x - (getSize().x/2), getPosition().y - (getSize().y/2));
        
        std::vector<std::unique_ptr<UI>> uiChildren;

    public:
        Container(std::string name);
        Container(std::string name, Vector position, Vector size, Color color, int bevel);
        // ~Container() noexcept override = default;
        void onStart() override;
        void drawUi() override;
	void drawFill(Vector &position, Vector &size, Color &color, int &bevel);
        int& getBevel();
        Vector& getSquareOrigin();
        void addChild(std::unique_ptr<UI> child);
        std::vector<std::unique_ptr<UI>>* getContainerChildren();
        void drawChildren(std::vector<std::unique_ptr<UI>> &children);
};
