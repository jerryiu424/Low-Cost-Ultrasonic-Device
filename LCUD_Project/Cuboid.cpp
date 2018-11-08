#include "Cuboid.h"
   
//constructor
Cuboid::Cuboid(int width,int length,int heigth){
    ID = s.getSensorID();
    volume = width*length*heigth;
}

std::string Cuboid::to_string(){
    "Type Cuboid with volume: " + getVolume();
}
