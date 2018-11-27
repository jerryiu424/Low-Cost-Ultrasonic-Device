#include "Cuboid.h"
   
//constructor
Cuboid::Cuboid(float width,float length,float heigth){
    Cwidth = width;
    Clength = length;
    Cheigth = heigth;

    MaxVolume = width*length*heigth;
    ShapeID = "Cuboid";
}

//get dimensions
float Cuboid::getCuboidWidth(){
    return Cwidth;
}

float Cuboid::getCuboidLength(){
    return Clength;
}

float Cuboid::getCuboidHeight(){
    return Cheigth;
}
std::string Cuboid::to_string(){
    return "Type Cuboid with volume: " + std::to_string(MaxVolume);
}