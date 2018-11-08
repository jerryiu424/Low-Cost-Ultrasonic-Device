#include "Cube.h"
   
//constructor
Cube::Cube(int side){
    ID = s.getSensorID();
    MaxVolume = side*side*side;
    volume = MaxVolume-side*side*getDistance();
}

std::string Cube::to_string(){
    "Type cube with volume: " + getVolume();
}
