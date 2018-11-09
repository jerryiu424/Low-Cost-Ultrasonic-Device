#ifndef CUBOID_H
#define CUBOID_H
#include "Container.h"

     
class Cuboid : public Container{
    private:
        int Cwidth,Clength,Cheigth;
    public:
        Cuboid(int width,int length,int heigth);
        ~Cuboid(){;}
        std::string to_string();
        int Cuboid::getWidth();
        int Cuboid::getLength();
        int Cuboid::getHeight();
};
#endif