#ifndef CONTAINER_H
#define CONTAINER_H
#include "Sensors.h"
     
class Container{
    protected:
        Sensors s;
        std::string ID;
        int MaxVolume;
        std::string ShapeID;
    public:
        Container();
        ~Container(){;}
        std::string getID();
        int getMaxVolume();
        std::string getShapeID();
        Sensors getSensor();
};
#endif