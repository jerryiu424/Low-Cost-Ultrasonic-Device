#include "Container.h"
   
//constructor
Container::Container(){
}

Sensors * Container::returnSensor(){
    Sensors *p;
    p = &s;
    return p;
}


