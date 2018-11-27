#ifndef CUBE_H
#define CUBE_H
#include "Container.h" 

class Cube : public Container{
    //attribute side
    private:
        float side;
    public:
        Cube(float s);
        ~Cube(){;}
        std::string to_string();
        float getCubeSide();
};
#endif
