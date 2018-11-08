#include "Cylinder.h"
   
//constructor
Cylinder::Cylinder(int radius, int heigth){
    ID = s.getSensorID();
    volume = 2*3.14*radius*heigth;
}

std::string Cylinder::to_string(){
    "Type Cylinder with volume: " + getVolume();
}
