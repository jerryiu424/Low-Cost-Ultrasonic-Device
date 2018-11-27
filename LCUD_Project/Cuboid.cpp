#include "Cuboid.h"
   
//constructor
Cuboid::Cuboid(int width,int length,int heigth){
    Cwidth = width;
    Clength = length;
    Cheigth = heigth;

    MaxVolume = width*length*heigth;
    ShapeID = "Cuboid";
}

//get dimensions
float Cuboid::getWidth(){
    return Cwidth;
}

float Cuboid::getLength(){
    return Clength;
}

float Cuboid::getHeight(){
    return Cheigth;
}
std::string Cuboid::to_string(){
    return "Type Cuboid with volume: " + getMaxVolume();
}
