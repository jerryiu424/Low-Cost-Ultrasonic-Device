#include "Cylinder.h"
   
//constructor
Cylinder::Cylinder(float radius, float heigth){
    Cradius = radius;
    Cheigth = heigth;
    MaxVolume = 2*3.14*radius*heigth;
    ShapeID = "Cylinder";
}

//get dimensions
float Cylinder::getCylinderRadius(){
    return Cradius;
}

float Cylinder::getCylinderHeight(){
    return Cheigth;
}


std::string Cylinder::to_string(){
    return "Type Cylinder with volume: " + std::to_string(MaxVolume);
}
