#include "Container.cpp"
#include "Cube.cpp"
#include "Sensors.cpp"
#include <iostream>

void doEverything(Cube*);

using namespace std;

int main(){
    float side_0 = 55.4;
    Cube vessel_0 (side_0);
    Cube *p0 = &vessel_0;
    doEverything(p0);
    
    float side_1 = 35.3;
    Cube vessel_1 (side_1);
    Cube *p1 = &vessel_1;
    doEverything(p1);

    
}

void doEverything(Cube *p){
    Sensors *s = (*p).returnSensor();

    cout<< "Sensor ID: " + (*s).getSensorID() << endl;
    cout << "Vessel has maximum volume of: "+to_string((*p).getMaxVolume()) << endl;
    cout << "This is a "+(*p).getShapeID() << endl;
    cout << "It has a side of: "+to_string((*p).getCubeSide()) << endl;

    (*s).update();
    float speedOfSoundM = 331+0.6*(*s).getTemperature();
	float speedOfSoundCM = speedOfSoundM*100;
	float distance = ((*s).getDuration()/2/1000000)*speedOfSoundCM;
	float level = (*p).getCubeSide() - distance;
	float volume = (*p).getCubeSide()*(*p).getCubeSide()*level;
    cout << (*p).getShapeID()+" Container with a volume of "+ to_string(volume)+" and has a water level of "+to_string(level) <<endl;
    cout << "current number of cubes: " + to_string(Sensors::getNumberOfSensors()) << endl;
    cout <<"\n";
}

