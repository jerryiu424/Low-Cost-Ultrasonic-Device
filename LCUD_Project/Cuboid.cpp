#include "Cuboid.h"
   
//constructor
Cuboid::Cuboid(int width,int length,int heigth){
    ID = s.getSensorID();
    MaxVolume = width*length*heigth;
    volume = width*length*getDistance();
}

std::string Cuboid::to_string(){
    "Type Cuboid with volume: " + getVolume();
}
