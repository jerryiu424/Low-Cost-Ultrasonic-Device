#include "Cylinder.h"
   
//constructor
Cylinder::Cylinder(int radius, int heigth){
    ID = s.getSensorID();
    Cradius = radius;
    Cheigth = heigth;
    MaxVolume = 2*3.14*radius*heigth;
    ShapeID = "Cylinder";
}

//get dimensions
int Cylinder::getRadius(){
    return Cradius;
}

int Cylinder::getHeight(){
    return Cheigth;
}


std::string Cylinder::to_string(){
    return "Type Cylinder with volume: " + getMaxVolume();
}
