#ifndef SENSORS_H
#define SENSORS_H
#include <string>

class Sensors{
    private:
        std::string SensorID,SDuration,STemperature;    //attributes ID, duration, and temperature
        static int NumSensors;    //static class varible NumSensors that keeps track of the total number of sensors 
    public:
        //constructor, destructor, getters, and toString methods
        Sensors();
        ~Sensors();
        int getNumberOfSensors(){return NumSensors;}
        std::string getIdentification(){return SensorID;}
        std::string getDuration(){return SDuration;}
        std::string getTemperature(){return STemperature;}
        std::string to_string();
        std::string getSensorID();
        std::string getTemperature();
        std::string getDuration();
        


};
//initialize number of sensors NumSensors to 0
int Sensors::NumSensors = 0;
#endif