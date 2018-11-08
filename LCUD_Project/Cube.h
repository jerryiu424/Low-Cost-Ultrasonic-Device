#ifndef CUBE_H
#define CUBE_H
#include <string>
#include "Container.cpp"

     
class Cube : public Container{
    private:
    public:
        Cube(float side);
        ~Cube(){;}
        std::string to_string();
        
};
#endif