#include <unistd.h>
#include <fstream>
#include <string>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>
#include "Sensors.h"

Sensors::Sensors(){
    std::ifstream inFile;
    //get number of current sensors, and increment total number of sensors by 1
	int ID = NumSensors;
    NumSensors++;

    SensorID = std::to_string(ID);    //convert int to string
	inFile.open("/dev/ttyACM" + SensorID);    //open file where sensor is located
    //while there is data, keep reading
    std::string line;    
	while(getline(inFile, line))
	{
        std::stringstream ss(line);
        std::string duration;
        getline(ss,duration, ' ');
        std::string temperature;
        getline(ss,temperature,' ');

	
        //if there is data, set attributes accordingly
        if(!duration.empty() && !temperature.empty()){
            SDuration = duration;
            STemperature = temperature;
        }

	usleep(100000);//pause for 1 second
    }	
	inFile.close();
}

std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+SDuration+" and temperature "+STemperature;  
}

std::string Sensors::getSensorID(){
    return sensorID;  
}


std::string Sensors::getTemperature(){
    return STemperature;  
}

std::string Sensors::getDuration(){
    return SDuration;  
}
