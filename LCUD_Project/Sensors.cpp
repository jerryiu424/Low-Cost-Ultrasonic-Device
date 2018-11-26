#include "Sensors.h"

//constructor
Sensors::Sensors(){
    usleep(1500000);
    //get number of current sensors, and increment total number of sensors by 1
	int ID = NumSensors;
    NumSensors++;
    SensorID = std::to_string(ID);    //convert int to string
	inFile.open("/dev/ttyACM" + SensorID);    //open file where sensor is located
    if(!inFile){
        throw std::runtime_error("Could not open file");
    }
}

//destructor
Sensors::~Sensors(){
    inFile.close();    //before object gets destroyed, close file
    NumSensors--;    //one less sensor
}

//read line output by arduino and store info in respective attributes
void Sensors::update(){
    std::string line;
    if (getline(inFile, line)){
        std::stringstream ss(line);
        std::string duration;
        getline(ss,duration, ' ');
        std::string temperature;
        getline(ss,temperature,' ');

        //if there is data, set attributes accordingly
        if(!duration.empty() && !temperature.empty()){
            SDuration = stof(duration);
            STemperature = stof(temperature);
             std::cout << duration; 
            std::cout << temperature;
        }
    }
}


//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+std::to_string(SDuration)+" and temperature "+std::to_string(STemperature);
}

