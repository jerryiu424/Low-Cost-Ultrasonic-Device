#ifndef CUBE_H
#define CUBE_H
#include <string>
#include "Container.cpp"

     
class Cube : public Container{
    private:
        int volume;
        
        
    public:
        Cube(float side);
        ~Cube(){;}
        int getVolume();
        std::string to_string();
        
};
#endif