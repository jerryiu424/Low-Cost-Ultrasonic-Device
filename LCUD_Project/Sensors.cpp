#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>
#include "Sensors.h"

//constructor
Sensors::Sensors(){
    //get number of current sensors
	int ID = NumSensors;
    SensorID = std::to_string(ID);    //convert int to string
    try{
	    inFile.open("/dev/ttyACM" + SensorID);    //open file where sensor is located
    }
    catch(exception e){
        throw "problem opening file!";
    }
    NumSensors++;    //increment total number of sensors by 1
}

//destructor
Sensors::~Sensors(){
    inFile.close();    //before object gets destroyed, close file
    NumSensors--;    //one less sensor
}

//read line output by arduino and store info in respective attributes
void Sensors::updateLine(){
    //if threres a line, read it and split
    std::string line;
    if (getline(inFile, line)){
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
    }
}

//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+SDuration+" and temperature "+STemperature;
}
