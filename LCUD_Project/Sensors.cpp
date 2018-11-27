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
        string duh;
        std::getline(inFile,duh);
        std::cout << duh << std::endl;
    }
    catch(std::exception e){
        throw "Problem opening file!";
    }
    NumSensors++;    //increment total number of sensors by 1
}

//destructor
Sensors::~Sensors(){
    inFile.close();    //before object gets destroyed, close file
    NumSensors--;    //one less sensor
}


void Sensors::update(){
    inFile.seekg(-1,std::ios_base::end);       //go to the last character in the file

    int boolLoop = 0;
    //keeps looping back, looking at characters until it finds the newline character
    while(boolLoop != 2){
        char ch;
        inFile.get(ch);
        //if it loops to the very beginning without ever 
        //seeing a newline character, the last line is the first line
        if((int)inFile.tellg() <= 1) {             // If the data was at or before the 0th byte
            inFile.seekg(0);                       // The first line is the last line
            boolLoop = 2;                // So stop there
        }
        //if newline found, we've found our last line
        else if(ch == '\n'){
            boolLoop ++;
        }
        else{
            inFile.seekg(-2,std::ios_base::cur);
        }
    }
    std::string line;
    getline(inFile,line);
    std::cout << line << std::endl;
    /*
    std::stringstream ss(line);
    std::cout << "LINE:" << ss.str() << std::endl;
    std::string duration;
    getline(ss,duration, ' ');
    //std::cout << "Duration!!!!!!: " << duration << std::endl;
    std::string temperature;
    getline(ss,temperature,' ');
    //std::cout << "temperature!!!!!!: " << temperature << std::endl;

    //if there is data, set attributes accordingly
    if(!duration.empty() && !temperature.empty()){
        SDuration = stof(duration);
        STemperature = stof(temperature);
    }
    */
}

//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+std::to_string(SDuration)+" and temperature "+std::to_string(STemperature);
}