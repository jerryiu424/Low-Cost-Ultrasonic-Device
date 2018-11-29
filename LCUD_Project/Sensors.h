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
 *              The attributes of the class are the ID of the sensor, the duration, temperature and a string
 *              that contains the data from the physical sensor.
 * 
 *  @author    Vance Gullberg
 */
class Sensors{
    private:
        std::string SensorID;
        float SDuration, STemperature;
        std::string file;
    public:
        Sensors();      // Function declaration for the constructor
        ~Sensors(){;}   // The destructor method
        void update();  // Function declaration for update()

        std::string getSensorID(){return SensorID;}
        float getDuration(){return SDuration;}    
        float getTemperature(){return STemperature;}
        
        std::string to_string();    // Function declaration for the to_string method, which will return a formatted string containing the duration and temperature
};
#endif