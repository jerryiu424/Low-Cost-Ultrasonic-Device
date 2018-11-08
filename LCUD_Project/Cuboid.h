#ifndef CUBOID_H
#define CUBOID_H
#include <string>
#include <fstream>
#include "Container.cpp"

     
class Cuboid : public Container{
    private:
        
    public:
        Cuboid();
        ~Cuboid(){;}
        std::string to_string();
        
};
#endif