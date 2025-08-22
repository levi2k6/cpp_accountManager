
#include "Container.hpp"
 
class VBox : public Container{
    private:
	Vector leftTop;
	Vector leftBottom;
	Vector rightTop;
	Vector rightBottom;

    public:
	VBox(std::string name) : Container(name){}
	VBox(std::string name, Vector position, Vector size, Color color, int bevel) 
	    : Container(name, position, size, color, bevel){}
	void controlChildren();
};
