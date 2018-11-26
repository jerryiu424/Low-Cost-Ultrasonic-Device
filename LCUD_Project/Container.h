#ifndef CONTAINER_H
#define CONTAINER_H
#include "Sensors.h"
     
class Container{
    protected:
        //attributes
        Sensors s;
        float MaxVolume;
        std::string ShapeID;
    public:
        //methods
        Container();
        ~Container(){;}
        float getMaxVolume(){return MaxVolume;}
        std::string getShapeID(){return ShapeID;}
        Sensors * returnSensor();
};
#endif
