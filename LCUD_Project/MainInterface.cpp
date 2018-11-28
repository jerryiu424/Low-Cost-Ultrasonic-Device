#include <iostream>
#include "Container.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Cuboid.h"
#include "Sensors.h"

using namespace std;
int main(){
    string shape;
    cout << "Please enter the shape of the container" << endl;
    cin >> shape;

    if(shape.compare("Cube")){
        string input;
        cout << "Please enter the side of the cube" << endl;
        cin >> input;
        float side = stof(input);
        Cube cubeObj (side);
    }
    else if(shape.compare("Cylinder")){
        string inputR;
        cout << "Please enter the radius of the cylinder" << endl;
        cin >> inputR;
        string inputH;
        cout << "Please enter the height of the cylinder" << endl;
        cin >> inputH;
        float radius = stof(inputR);
        float height = stof(inputH);
        Cylinder cylObj (radius,height);
    }
    else if(shape.compare("Cuboid")){
        string inputW;
        cout << "Please enter the width of the cuboid" << endl;
        cin >> inputW;
        string inputL;
        cout << "Please enter the length of the cuboid" << endl;
        cin >> inputL;
        string inputH;
        cout << "Please enter the height of the cuboid" << endl;
        cin >> inputH;
        float width = stof(inputW);
        float length = stof(inputL);
        float height = stof(inputH);
        Cuboid cuboidObj (width,length,height);
    }
    else{
        cout << "Invalid shape" << endl;
    }


    return 0;
}