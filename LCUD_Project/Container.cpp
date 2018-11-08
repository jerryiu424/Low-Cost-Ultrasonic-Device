#include "Container.h"
   
//constructor
Container::Container(){
    ID = s.getSensorID();
}

int Container::getDistance(){
}


std::string Container::getID(){
    return ID;
}


int Container::getMaxVolume(){
    return MaxVolume;
}