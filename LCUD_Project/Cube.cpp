#include "Cube.h"
   
//constructor
Cube::Cube(int side){
    ID = s.getSensorID();
    MaxVolume = side*side*side;
}

std::string Cube::to_string(){
    return "Type cube with volume: " + getMaxVolume();
}
