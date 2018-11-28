#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
//#include "Container.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"
//#include "Sensors.h"
using namespace std;

void CubeFunc(Cube);
void CylinderFunc(Cylinder);
void CuboidFunc(Cuboid);

Cube createCube();
Cylinder createCylinder();
Cuboid createCuboid();

using namespace std;
ifstream inFile;

int main(){
    string shape;
    inFile.open("data.txt");
    if(inFile){
        getline(inFile,shape);
        if(shape.compare("CUBE") == 0){
            string side;
            getline(inFile,side);
            float s = stof(side);
            Cube cube (s);
            CubeFunc(cube);
        }
        else if(shape.compare("CYLINDER") == 0){
            string radius;
            getline(inFile,radius);
            string height;
            getline(inFile,height);
            float r = stof(radius);
            float h = stof(height);
            Cylinder cylinder (r,h);   
            CylinderFunc(cylinder);    
        }
        else if (shape.compare("CUBOID") == 0){
            string width;
            getline(inFile,width);
            string length;
            getline(inFile,length);
            string height;
            getline(inFile,height);
            float w = stof(width);
            float l = stof(length);
            float h = stof(height);
            Cuboid cuboid (w,l,h);
            CuboidFunc(cuboid);
        }
    }

    else{
        ofstream outFile;
        outFile.open("data.txt");
        string shape;
        cout << "Please enter the shape of the container" << endl;
        cin >> shape;
        shape = boost::to_upper(shape);
        if(shape.compare("CUBE") == 0){
            Cube cube = createCube();
            float side = cube.getCubeSide();
            outFile << shape + "\n";
            outFile << to_string(side) + "\n";
            outFile.close();
            CubeFunc(cube);
        }
        else if(shape.compare("CYLINDER") == 0){
            Cylinder cylinder = createCylinder();
            float height = cylinder.getCylinderHeight();
            float radius = cylinder.getCylinderRadius();
            outFile << shape + "\n";
            outFile << to_string(height) + "\n";
            outFile << to_string(radius) + "\n";
            outFile.close();
            CylinderFunc(cylinder);
        }
        else if(shape.compare("CUBOID") == 0){
            Cuboid cuboid = createCuboid();
            float length = cuboid.getCuboidLength();
            float width = cuboid.getCuboidWidth();
            float height = cuboid.getCuboidHeight();
            outFile << shape + "\n";
            outFile << to_string(length) + "\n";
            outFile << to_string(width) + "\n";
            outFile << to_string(height) + "\n";
            outFile.close();
            CuboidFunc(cuboid);
        }
        else{
            cout << "Invalid shape" << endl;
        }
    }

    return 0;
}

Cube createCube(){
    string input;
    cout << "Please enter the length for the sides of the cube (cm):" << endl;
    cin >> input;
    float side = stof(input);
    Cube cubeObj (side);
    return cubeObj;
}

Cylinder createCylinder(){
    string inputR;
    cout << "Please enter the radius of the cylinder (cm):" << endl;
    cin >> inputR;
    string inputH;
    cout << "Please enter the height of the cylinder (cm):" << endl;
    cin >> inputH;
    float radius = stof(inputR);
    float height = stof(inputH);
    Cylinder cylObj (radius,height);
    return cylObj;    
}

Cuboid createCuboid(){
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
    return cuboidObj;
}

void CubeFunc(Cube c){
    Sensors s = c.returnSensor();

    cout<< "Sensor ID: " + s.getSensorID() << endl;
    cout << "Vessel has maximum volume of: " + to_string(c.getMaxVolume()) << endl;
    cout << "This is a " + c.getShapeID() << endl;
    cout << "It has a side of: " + to_string(c.getCubeSide()) << endl;

    while(true){
        s.update();
        float speedOfSoundM = 331+0.6*s.getTemperature();
        float speedOfSoundCM = speedOfSoundM*100;
        float distance = (s.getDuration()/2/1000000)*speedOfSoundCM;
        float level = c.getCubeSide() - distance;
        float volume = c.getCubeSide()*c.getCubeSide()*level;
        cout << c.getShapeID()+" Container with a volume of "+ to_string(volume)+" and has a water level of "+to_string(level) <<endl;
      //  cout << "current number of cubes: " + to_string(Sensors::getNumberOfSensors()) << endl;
        cout <<"\n";
    }
}

void CylinderFunc(Cylinder c){

}

void CuboidFunc(Cuboid c){

}