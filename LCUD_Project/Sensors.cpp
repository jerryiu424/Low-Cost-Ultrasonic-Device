#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <bits/stdc++.h>
#include "Sensors.h"

//constructor
Sensors::Sensors(){
    //get number of current sensors, and increment total number of sensors by 1
	int ID = NumSensors;
    NumSensors++;
    SensorID = std::to_string(ID);    //convert int to string
	inFile.open("/dev/ttyACM" + SensorID);    //open file where sensor is located
}

//destructor
Sensors::~Sensors(){
    inFile.close();    //before object gets destroyed, close file
<<<<<<< HEAD
    NumSensors--;    //one less sensor
=======
>>>>>>> 859b84991d2c4365b3e9f5e4054e792bc01dbe2f
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

<<<<<<< HEAD

=======
>>>>>>> 859b84991d2c4365b3e9f5e4054e792bc01dbe2f
//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+SDuration+" and temperature "+STemperature;
}
<<<<<<< HEAD

=======
>>>>>>> 859b84991d2c4365b3e9f5e4054e792bc01dbe2f
