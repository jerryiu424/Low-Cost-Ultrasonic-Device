#include "Cylinder.h"
   
//constructor
Cylinder::Cylinder(int radius, int heigth){
    ID = s.getSensorID();
    MaxVolume = 2*3.14*radius*heigth;
    volume = MaxVolume-2*3.14*radius*getDistance();
}

std::string Cylinder::to_string(){
    "Type Cylinder with volume: " + getVolume();
}