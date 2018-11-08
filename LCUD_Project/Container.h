#ifndef CONTAINER_H
#define CONTAINER_H
#include "Sensors.cpp"
     
class Container{
    private:
        Sensors s;
        int distance;
        int temperature;
    public:
        Container();
        ~Container(){;}
        int getDistance();
        int gertemperature();
        std::string to_string();
        
};
#endif