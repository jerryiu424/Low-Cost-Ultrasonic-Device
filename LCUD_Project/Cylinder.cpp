#include "Cylinder.h"
   
//constructor
Cylinder::Cylinder(int radius, int heigth){
    ID = s.getSensorID();
    MaxVolume = 2*3.14*radius*heigth;
    
}

std::string Cylinder::to_string(){
    return "Type Cylinder with volume: " + getMaxVolume();
}
