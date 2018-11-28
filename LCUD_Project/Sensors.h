#ifndef SENSORS_H
#define SENSORS_H
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <dirent.h>
#include <bits/stdc++.h>

class Sensors{
    private:
        std::string SensorID;
        float SDuration, STemperature;    //attributes ID, duration, and temperature
        int NumSensors;    //static class varible NumSensors that keeps track of the total number of sensors 
        std::string file;
    public:
        //constructor, destructor, getters, and toString methods
        Sensors();
        ~Sensors();
        static int getNumberOfSensors(){return NumSensors;}
        void update();
        std::string getSensorID(){return SensorID;}
        float getDuration(){return SDuration;}
        float getTemperature(){return STemperature;}
        std::string to_string();
};
//initialize number of sensors NumSensors to 0
//int Sensors::NumSensors = 0;
#endif