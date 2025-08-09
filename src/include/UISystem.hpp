#pragma once

class Vector;

class UISystem{

    private:

    public:
        void drawLine( const Vector& start, const Vector& end);
        void drawPoint(const Vector& position);
        void drawCircle(const Vector center, int radius);
        void createBox(const Vector& size, const Vector& position);

};

extern UISystem uiSystem;



