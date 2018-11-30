#include "Cylinder.h"
   
//constructor
Cylinder::Cylinder(float radius, float height){
    Cradius = radius;
    Cheight = height;
    MaxVolume = 2*3.14*radius*height;
    ShapeID = "Cylinder";
}

std::string Cylinder::to_string(){
    return "Type Cylinder with volume: " + std::to_string(MaxVolume);
}
    