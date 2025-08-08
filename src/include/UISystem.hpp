#pragma once

class Color;
class Vector;

class UISystem{

    private:

    public:
        void drawLine(const Color& color, const Vector& start, const Vector& end);

};

extern UISystem uiSystem;



