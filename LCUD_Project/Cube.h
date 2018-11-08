#ifndef CUBE_H
#define CUBE_H
#include "Container.cpp"

     
class Cube : public Container{
    private:
    public:
        Cube(int side);
        ~Cube(){;}
        std::string to_string();
        
};
#endif