
#include "Container.hpp"
#include "Enums.hpp"
 
class HBox : public Container{
    private:
	int type = uiVbox;
	Vector leftTop;
	Vector leftBottom;
	Vector rightTop;
	Vector rightBottom;

    public:
	HBox(std::string name) : Container(name){}
	HBox(std::string name, Vector position, Vector size, Color color, int bevel) 
	    : Container(name, position, size, color, bevel){}

	const int& getType() const override; 
	void setChildrenPosition() override; 

	void controlChildren();
};
