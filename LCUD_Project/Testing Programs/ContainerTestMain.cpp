#include "Container.cpp"
#include "Cube.cpp"
#include "Sensors.cpp"
#include <iostream>

void doEverything(Cube*);

using namespace std;

int main(){
    float side_0 = 55.4;
    Cube vessel_0 (side_0);
    doEverything(vessel_0);
    
    float side_1 = 35.3;
    Cube vessel_1 (side_1);
    doEverything(vessel_1);
}

void doEverything(Cube c){
    Sensors s = c.returnSensor();

    cout<< "Sensor ID: " + s.getSensorID() << endl;
    cout << "Vessel has maximum volume of: "+to_string(c.getMaxVolume()) << endl;
    cout << "This is a "+c.getShapeID() << endl;
    cout << "It has a side of: "+to_string(c.getCubeSide()) << endl;

    s.update();
    float speedOfSoundM = 331+0.6*s.getTemperature();
	float speedOfSoundCM = speedOfSoundM*100;
	float distance = (s.getDuration()/2/1000000)*speedOfSoundCM;
	float level = c.getCubeSide() - distance;
	float volume = c.getCubeSide()*c.getCubeSide()*level;
    cout << c.getShapeID()+" Container with a volume of "+ to_string(volume)+" and has a water level of "+to_string(level) <<endl;
    cout << "current number of cubes: " + to_string(Sensors::getNumberOfSensors()) << endl;
    cout <<"\n";
}

