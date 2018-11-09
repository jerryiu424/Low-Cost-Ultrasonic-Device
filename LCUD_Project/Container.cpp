#include "Container.h"
   
//constructor
Container::Container(){
    ID = s.getSensorID();
}

//get ide
std::string Container::getID(){
    return ID;
}

//get max volume
int Container::getMaxVolume(){
    return MaxVolume;
}

//get shape
std::string Container::getShapeID(){
    return ShapeID;
}

//get duration from sensor
int Container::getDuration(){
    return stoi(s.getDuration());
}

//get temp from sensor
int Container::getTemperature(){
    return stoi(s.getTemperature());
}

//update
void Container::update(){
    s.updateLine();
}

