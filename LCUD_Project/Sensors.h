#ifndef SENSORS_H
#define SENSORS_H
#include <string>
#include <fstream>
<<<<<<< HEAD

class Sensors{
    private:
        std::string SensorID, SDuration, STemperature;    //attributes ID, duration, and temperature
        std::ifstream inFile;    //read from file
=======


class Sensors{
    private:
        std::string SensorID,SDuration,STemperature;    //attributes ID, duration, and temperature
        std::ifstream inFile;    //read from file 
>>>>>>> 859b84991d2c4365b3e9f5e4054e792bc01dbe2f
        static int NumSensors;    //static class varible NumSensors that keeps track of the total number of sensors 
    public:
        //constructor, destructor, getters, and toString methods
        Sensors();
        ~Sensors();
<<<<<<< HEAD
        static int getNumberOfSensors(){return NumSensors;}
=======
        int getNumberOfSensors(){return NumSensors + 1;}
>>>>>>> 859b84991d2c4365b3e9f5e4054e792bc01dbe2f
        void updateLine();
        std::string getSensorID(){return SensorID;}
        std::string getDuration(){return SDuration;}
        std::string getTemperature(){return STemperature;}
        std::string to_string();
};
//initialize number of sensors NumSensors to 0
int Sensors::NumSensors = 0;
#endif

