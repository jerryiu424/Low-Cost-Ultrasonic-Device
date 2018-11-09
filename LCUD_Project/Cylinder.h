#ifndef CYLINDER_H
#define CYLINDER_H
#include "Container.h"
     
class Cylinder : public Container{
    private:
        int Cradius, Cheigth;
    public:
        Cylinder(int radius, int height);
        ~Cylinder(){;}
        std::string to_string();
        int getRadius();
        int getHeight();        
};
#endif