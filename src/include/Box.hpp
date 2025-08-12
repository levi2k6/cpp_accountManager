#pragma once
#include <iostream>
#include <vector>
#include "Types.hpp" 
#include "Renderer.hpp"
#include "UI.hpp"


class Box : public UI{
    private:
        Vector position = Vector(0, 0);//x, y
        Vector size = Vector(10, 10); //x, y
        Color color = Color(255, 255, 255, 0);//r, g, b, alpha 
        std::vector<UI> children;

    public:
        Box();
        Box(Vector position, Vector size, Color color);
        void drawUi() override;
        void createBox(const Vector& position , const Vector& size);
        Vector &getPosition();
        void setPosition(const int &x, const int &y);
        Vector &getSize();
        void setSize(const int &x, const int &y);
        Color &getColor();
        void setColor(const uint8_t &r, const uint8_t &b, const uint8_t &g, const uint8_t &alpha);

};
