#include "Container.h"
   
//constructor
Container::Container(){
    ID = s.getSensorID();
}

int Container::getDistance(){
    int speed = 331.1 + stoi(s.getTemperature())*0.6;
    distance = speed*stoi(s.getDuration())/2;
}

int Container::gertemperature(){
    return stoi(s.getTemperature());
}

std::string Container::getID(){
    return ID;
}

int Container::getVolume(){
    return volume;
}

std::string Container::to_string(){
}
