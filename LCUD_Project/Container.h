#ifndef CONTAINER_H
#define CONTAINER_H
#include "Sensors.cpp"
     
class Container{
    private:
        Sensors s;
        std::string ID;
        int distance;
        int temperature;
    public:
        Container();
        ~Container(){;}
        std::string getID();
        int getDistance();
        int gertemperature();
        std::string to_string();
        
};
#endif