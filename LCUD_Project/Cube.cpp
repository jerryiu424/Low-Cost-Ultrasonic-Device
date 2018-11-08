#include "Cube.h"
   
//constructor
Cube::Cube(float side){
    volume = side*side*side;
}

int Cube::getVolume(){
    return volume;
}
std::string Cube::to_string(){
}
