#ifndef SENSORS_H
#define SENSORS_H
#include <string>
#include <fstream>
     
class Sensors{
    private:
        std::string SensorID, SDuration, STemperature;    //attributes ID, duration, and temperature
        std::ifstream inFile;    //read from file
        static int NumSensors;    //static class varible NumSensors that keeps track of the total number of sensors 
    public:
        //constructor, destructor, getters, and toString methods
        Sensors();
        ~Sensors();
        static int getNumberOfSensors(){return NumSensors;}
        void updateLine();
        std::string getSensorID(){return SensorID;}
        std::string getDuration(){return SDuration;}
        std::string getTemperature(){return STemperature;}
        std::string to_string();
};
//initialize number of sensors NumSensors to 0
int Sensors::NumSensors = 0;
#endif