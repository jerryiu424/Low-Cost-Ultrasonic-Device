#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>
#include "Sensors.h"
   
//constructor
Sensors::Sensors(){
    //get number of current sensors
	int ID = 0; //NumSensors;
    SensorID = std::to_string(ID);    //convert int to string
    file = "/dev/ttyACM" + SensorID;
    //NumSensors++;    //increment total number of sensors by 1
}

//destructor
Sensors::~Sensors(){
    //NumSensors--;    //one less sensor
}


void Sensors::update(){
    std::ifstream inFile;
    inFile.open(file);
    //if threres a line, read it and split
    std::string line;
    if (getline(inFile, line)){
        std::cout << "Hello from Sensors::update()\n" << std::endl;
        std::stringstream ss(line);
        std::string duration;
        getline(ss,duration, ' ');
        std::string temperature;
        getline(ss,temperature,' ');

        //if there is data, set attributes accordingly
        if(!duration.empty() && !temperature.empty()){
            SDuration = stof(duration);
            STemperature = stof(temperature);
        }
        std::cout << duration + '\t' + temperature + '\n' << std::endl;
    }
    inFile.close();
}

//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+std::to_string(SDuration)+" and temperature "+std::to_string(STemperature);
}