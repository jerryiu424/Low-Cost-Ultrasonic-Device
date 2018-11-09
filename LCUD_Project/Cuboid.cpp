#include "Cuboid.h"
   
//constructor
Cuboid::Cuboid(int width,int length,int heigth){
    ID = s.getSensorID();
    Cwidth = width;
    Clength = length;
    Cheigth = heigth;

    MaxVolume = width*length*heigth;
    ShapeID = "Cuboid";
}

int Cuboid::getWidth(){
    return Cwidth;
}

int Cuboid::getLength(){
    return Clength;
}

int Cuboid::getHeight(){
    return Cheigth;
}
std::string Cuboid::to_string(){
    return "Type Cuboid with volume: " + getMaxVolume();
}
