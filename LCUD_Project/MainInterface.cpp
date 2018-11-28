#include <iostream>
#include "Container.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"
#include "Sensors.h"
using namespace std;

void inputFunc();
void CubeFunc(Container);
void CylinderFunc();
void CuboidFunc();

int main(){



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
    }
    else{
        cout << "Invalid shape" << endl;
    }
}