#ifndef CUBOID_H
#define CUBOID_H
#include "Container.h"

     
class Cuboid : public Container{
    //attribute dimensions
    private:
        float Cwidth,Clength,Cheigth;
    public:
        Cuboid(float width,float length,float heigth);
        ~Cuboid(){;}
        std::string to_string();
        float Cuboid::getCuboidWidth();
        float Cuboid::getCuboidLength();
        float Cuboid::getCuboidHeight();
}; 
#endif