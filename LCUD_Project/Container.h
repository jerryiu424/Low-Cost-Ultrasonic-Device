#ifndef CONTAINER_H
#define CONTAINER_H
#include "Sensors.cpp"
     
class Container{
    protected:
        Sensors s;
        std::string ID;
        int MaxVolume;
    public:
        Container();
        ~Container(){;}
        std::string getID();
        int getMaxVolume();
        
};
#endif