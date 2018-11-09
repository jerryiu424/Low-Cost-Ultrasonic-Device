#ifndef CONTAINER_H
#define CONTAINER_H
#include "Sensors.h"
     
class Container{
    protected:
        //attributes
        Sensors s;
        std::string ID;
        int MaxVolume;
        std::string ShapeID;
    public:
        //methods
        Container();
        ~Container(){;}
        std::string getID();
        int getMaxVolume();
        std::string getShapeID();
        int getDuration();
        int getTemperature();
        void update();
};
#endif