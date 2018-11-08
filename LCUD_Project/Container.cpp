#include "Container.h"
   
//constructor
Container::Container(){
    ID = s.getSensorID();
}

std::string Container::getID(){
    return ID;
}

int Container::getMaxVolume(){
    return MaxVolume;
}

std::string Container::getShapeID(){
    return ShapeID;
}

Sensors Container::getSensor(){
    return s;
}