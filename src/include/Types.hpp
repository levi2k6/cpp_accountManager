#pragma once
#include <cstdint>

class Color{

    public: 
        uint8_t r = 255;
        uint8_t g = 255;
        uint8_t b = 255;
        uint8_t alpha = 255; 

        Color(uint8_t r, uint8_t g, uint8_t b, uint8_t alpha) : r(r), g(g), b(b){};
};

class Vector{
    public: 
        int x = 0;
        int y = 0;

        Vector(int x, int y) : x(x), y(y){};
};







