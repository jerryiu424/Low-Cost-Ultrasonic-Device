#include "Cuboid.h"
   
//constructor
Cuboid::Cuboid(float width,float length,float height){
    Cwidth = width;
    Clength = length;
    Cheight = height;

    MaxVolume = width*length*height;
    ShapeID = "Cuboid";
}

std::string Cuboid::to_string(){
    return "Type Cuboid with volume: " + std::to_string(MaxVolume);
}