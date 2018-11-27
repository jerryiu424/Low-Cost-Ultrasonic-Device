#ifndef CYLINDER_H
#define CYLINDER_H
#include "Container.h"
     
class Cylinder : public Container{
    //attributes
    private:
        int Cradius, Cheigth;
    public:
        Cylinder(int radius, int height);
        ~Cylinder(){;}
        std::string to_string();
        float getRadius();
        float getHeight();        
};
#endif