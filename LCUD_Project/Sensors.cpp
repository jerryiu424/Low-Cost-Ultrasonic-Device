/**
 * /brief Sensors class methods
 * 
 * 
 *
 */
#include "Sensors.h"
   
//constructor
Sensors::Sensors(){
	int ID = 0; //sensorID;
    SensorID = std::to_string(ID);    //convert int to string
    file = "/dev/ttyACM" + SensorID;
    //NumSensors++;    //increment total number of sensors by 1
}

//destructor
Sensors::~Sensors(){
}


void Sensors::update(){
    std::ifstream inFile;
    inFile.open(file);
    //if threres a line, read it and split
    std::string line;
    if (getline(inFile, line)){
        //std::cout << "Hello from Sensors::update()" << std::endl; //remove me!
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
        //std::cout << duration + '\t' + temperature << std::endl; //remove me!
    }
    inFile.close();
}

//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+std::to_string(SDuration)+" and temperature "+std::to_string(STemperature);
}