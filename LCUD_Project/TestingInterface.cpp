#include <iostream>
#include "Container.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"
#include "Sensors.h"
using namespace std;

void inputFunc();
void CubeFunc(Cube);
void CylinderFunc(Cylinder);
void CuboidFunc(Cuboid);

Container arr[4];
int main(){
    while(true){
        for(int i=0;i<Sensors::getNumberOfSensors();i++){
            if(arr[i].getShapeID() == "Cube"){
                CubeFunc(arr[i]);
            }
            else if(arr[i].getShapeID() == "Cylinder"){
                CylinderFunc(arr[i]);        
            }
            else{
                CuboidFunc(arr[i]);
            }
        }
        if(Sensors::getNumberOfSensors() == 4){
            cout << "Already at max number of sensors!!" << endl;
        }
        else{
            string input;
            cout << "Would you like to enter another sensor (y/n)" << endl;
            cin >> input;
            if(input == "y"){
                inputFunc();
            }
        }
    }
    return 0;
}

void inputFunc(){
    string shape;
    cout << "Please enter the shape of the container" << endl;
    cin >> shape;

    if(shape.compare("Cube")){
        string input;
        cout << "Please enter the length for the sides of the cube (cm):" << endl;
        cin >> input;
        float side = stof(input);
        Cube cubeObj (side);
        arr[Sensors::getNumberOfSensors() - 1] = cubeObj;
    }
    else if(shape.compare("Cylinder")){
        string inputR;
        cout << "Please enter the radius of the cylinder (cm):" << endl;
        cin >> inputR;
        string inputH;
        cout << "Please enter the height of the cylinder (cm):" << endl;
        cin >> inputH;
        float radius = stof(inputR);
        float height = stof(inputH);
        Cylinder cylObj (radius,height);
        arr[Sensors::getNumberOfSensors() - 1] = cylObj;
    }
    else if(shape.compare("Cuboid")){
        string inputW;
        cout << "Please enter the width of the cuboid (cm):" << endl;
        cin >> inputW;
        string inputL;
        cout << "Please enter the length of the cuboid (cm):" << endl;
        cin >> inputL;
        string inputH;
        cout << "Please enter the height of the cuboid (cm):" << endl;
        cin >> inputH;
        float width = stof(inputW);
        float length = stof(inputL);
        float height = stof(inputH);
        Cuboid cuboidObj (width,length,height);
        arr[Sensors::getNumberOfSensors() - 1] = cuboidObj;
    }
    else{
        cout << "Invalid shape" << endl;
    }
}

void CubeFunc(Cube c){
    Sensors s = c.returnSensor();

    cout<< "Sensor ID: " + s.getSensorID() << endl;
    cout << "Vessel has maximum volume of: " + to_string(c.getMaxVolume()) << endl;
    cout << "This is a " + c.getShapeID() << endl;
    cout << "It has a side of: " + to_string(c.getCubeSide()) << endl;

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

void CylinderFunc(Cylinder c){

}

void CuboidFunc(Cuboid c){

}