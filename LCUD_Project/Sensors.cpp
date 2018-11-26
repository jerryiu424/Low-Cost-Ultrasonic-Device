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
    inFile.seekg(-1,std::ios_base::end);       //go to the last character in the file         
    bool boolLoop = true;
    //keeps looping back, looking at characters until it finds the newline character
    while(boolLoop){
        char ch;
        inFile.get(ch);
        //if it loops to the very beginning without ever 
        //seeing a newline character, the last line is the first line
        if((int)inFile.tellg() <= 1) {             // If the data was at or before the 0th byte
            inFile.seekg(0);                       // The first line is the last line
            boolLoop = false;                // So stop there
        }
        //if newline found, we've found our last line
        else if(ch == '\n'){
            boolLoop = false;
        }
        else{
            inFile.seekg(-2,std::ios_base::cur);
        }
    }
    std::string line;
    getline(inFile,line);
    std::stringstream ss(line);
    std::string duration;
    getline(ss,duration, ' ');
    std::string temperature;
    getline(ss,temperature,' ');
    allinfo = duration+temperature;
    /*
    SDuration = stof(duration);
    STemperature = stof(temperature);
    */
}


//tostring
std::string Sensors::to_string(){
    return "Sensor number "+SensorID+" currently has duration "+std::to_string(SDuration)+" and temperature "+std::to_string(STemperature);
}

