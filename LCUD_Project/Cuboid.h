#ifndef CUBOID_H
#define CUBOID_H
#include "Container.h"

     
class Cuboid : public Container{
    //attribute dimensions
    private:
        int Cwidth,Clength,Cheigth;
    public:
        Cuboid(int width,int length,int heigth);
        ~Cuboid(){;}
        std::string to_string();
        float Cuboid::getCuboidWidth();
        float Cuboid::getCuboidLength();
        float Cuboid::getCuboidHeight();
};
#endif