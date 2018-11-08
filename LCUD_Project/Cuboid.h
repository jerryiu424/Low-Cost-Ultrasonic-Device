#ifndef CUBOID_H
#define CUBOID_H
#include "Container.h"
     
class Cuboid : public Container{
    private:
    public:
        Cuboid(int width,int length,int heigth);
        ~Cuboid(){;}
        std::string to_string();
};
#endif