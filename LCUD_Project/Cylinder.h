#ifndef CYLINDER_H
#define CYLINDER_H
#include <string>
#include <fstream>
#include "Container.cpp"
     
class Cylinder : public Container{
    private:
        
    public:
        Cylinder();
        ~Cylinder(){;}
        std::string to_string();
        
};
#endif