#ifndef CONTAINER_H
#define CONTAINER_H
#include "Sensors.cpp"
     
class Container{
    protected:
        Sensors s;
        std::string ID;
        int distance;
        int temperature;
        int volume;
    public:
        Container();
        ~Container(){;}
        std::string getID();
        int getDistance();
        int gertemperature();
        int getVolume();
        
};
#endif