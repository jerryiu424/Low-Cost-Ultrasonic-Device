#ifndef CUBE_H
#define CUBE_H
#include "Container.h" 
     
class Cube : public Container{
    private:
    public:
        Cube(int side);
        ~Cube(){;}
        std::string to_string();
};
#endif