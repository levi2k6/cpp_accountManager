#pragma once
#include <iostream>
#include "../include/Types.hpp"

class UI{

    private:

        std::string name = "";
        Vector position = Vector(0,0);//x, y
        Vector size = Vector(0,0); //x, y
        Color color = Color(0,0,0,0);//r, g, b, alpha 

    public:
        UI(std::string name);
        UI(std::string name, Vector position, Vector size, Color color);
        std::string getName();
        void setName(std::string name);
        Vector &getPosition();
        void setPosition(const int &x, const int &y);
        Vector &getSize();
        void setSize(const int &x, const int &y);
        Color &getColor();
        void setColor(const uint8_t &r, const uint8_t &b, const uint8_t &g, const uint8_t &alpha);

        virtual void onStart(){};
        virtual void drawUi(){};   
        virtual ~UI(){};
};

