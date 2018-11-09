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

int Container::getDuration(){
    return stoi(s.getDuration());
}

int Container::getTemperature(){
    return stoi(s.getTemperature());
}

void Container::update(){
    s.updateLine();
}

