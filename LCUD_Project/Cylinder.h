#ifndef CYLINDER_H
#define CYLINDER_H
#include "Container.h"
     
class Cylinder : public Container{
    //attributes
    private:
        float Cradius, Cheigth;
    public:
        Cylinder(float radius, float height);
        ~Cylinder(){;}
        std::string to_string();
        float getCylinderRadius();
        float getCylinderHeight();        
};
#endif