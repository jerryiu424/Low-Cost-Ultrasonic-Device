#ifndef SENSORS_H
#define SENSORS_H
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <dirent.h>
#include <bits/stdc++.h>

/** 
 *  @brief      The Sensor class for the device.
 *
 *  @details    This class utilizes the sensor connected to the Arduino and stores the values it recieves
 *              into attributes that can be used to calculate the volume in a container.
 *              The attributes of the class are the ID of the sensor, the duration, temperature 
 * 
 *  @author    Vance Gullberg
 */
class Sensors{
    private:
        std::string SensorID;
        float SDuration, STemperature;    //attributes ID, duration, and temperature
        static int NumSensors;    //static class varible NumSensors that keeps track of the total number of sensors 
        std::string file;
    public:
        //constructor, destructor, getters, and toString methods
        Sensors();
        ~Sensors();
        void update();
        std::string getSensorID(){return SensorID;}
        float getDuration(){return SDuration;}
        float getTemperature(){return STemperature;}
        std::string to_string();
};
#endif