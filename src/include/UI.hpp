#pragma once
#include "../include/Types.hpp"
#include "../include/Enums.hpp"

class UI{

    private:
	int type = uiBox;
        std::string name = "";
        Vector position = Vector(0,0);//x, y
        Vector size = Vector(0,0); //x, y
        UI *parent = nullptr;
        Vector innerPosition = Vector(0,0);
        Color color = Color(0,0,0,0);//r, g, b, alpha 

    public:
        UI(std::string name);
        UI(std::string name, Vector position, Vector size, Color color);


	virtual const int& getType() const;
	virtual void onStart(){};
        virtual void drawUi(){};   
        virtual ~UI() noexcept = default;


        std::string getName();
        void setName(std::string name);
        Vector &getPosition();
        void setPosition(Vector &position);
        UI* getParent();
        void setParent(UI *parent);
        Vector &getInnerPosition();
        void setInnerPosition(Vector &position);
        Vector &getSize();
        void setSize(const int &x, const int &y);
        Color &getColor();
        void setColor(const uint8_t &r, const uint8_t &b, const uint8_t &g, const uint8_t &alpha);

       };

