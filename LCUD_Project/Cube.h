#ifndef CUBE_H
#define CUBE_H
#include <string>
#include <fstream>
#include "Container.cpp"

     
class Cube : public Container{
    private:
        
    public:
        Cube();
        ~Cube(){;}
        std::string to_string();
        
};
#endif