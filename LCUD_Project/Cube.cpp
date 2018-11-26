#include "Cube.h"
   
//constructor
Cube::Cube(float s){
    MaxVolume = s*s*s;
    ShapeID = "Cube";
    side  = s;
}

//get sides
float Cube::getSide(){
    return side;
}

std::string Cube::to_string(){
    return "Type cube with volume: " + std::to_string(MaxVolume) + " and side: " + std::to_string(side);
}

