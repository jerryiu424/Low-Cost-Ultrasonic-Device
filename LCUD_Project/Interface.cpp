//g++ -o main_interface Interface.cpp Cube.cpp Cylinder.cpp Cuboid.cpp Container.cpp Sensors.cpp -L/usr/include/mysql -lmysqlclient -I/usr/include/mysql

#include "Interface.h"
ifstream inFile;

MYSQL mysql,*connection;
MYSQL_RES result;
MYSQL_ROW row;

char * ip = (char*)"127.0.0.1";
char * usr = (char*)"root";
char * pass = (char*)"group10";
char * db = (char*)"group10";

int query_state;
float avgVolume;
float avgDistance;
float avgLevel;
int counter = 0;

int main(){
    string shape;
    inFile.open("data.txt");

    if(inFile){
        cout << "Data.txt exists!"
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
            cout << "Set values";
            Cylinder cylinder (r,h);
            cout << "Value Created";   
            CylinderFunc(cylinder); 
            cout << "Never will be seen!";   
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
        
        for (int i=0; i<shape.length(); i++)
        shape[i] = toupper(shape[i]);

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

    mysql_init(&mysql);
    connection = mysql_real_connect(&mysql, ip, usr, pass, db, 0, NULL, 0);

    while(true){
        s.update();
        float speedOfSoundM = 331+0.6*s.getTemperature();
        float speedOfSoundCM = speedOfSoundM*100;
        float distance = (s.getDuration()/2/1000000)*speedOfSoundCM;
        float level = c.getCubeSide() - distance;
        float volume = c.getCubeSide()*c.getCubeSide()*level;

        if(volume >= c.getMaxVolume() || volume < 0)
        {
            continue;
        }
    
        cout << c.getShapeID()+" Container with a volume of "+ to_string(volume)+" and has a water level of "+to_string(level) <<endl;
        cout <<"\n";

        avgVolume = avgVolume + volume;
        avgDistance = avgDistance + distance;
        avgLevel = avgLevel + level;
        counter++;

        if(counter == 10){
            avgVolume = avgVolume/counter;
            avgDistance = avgDistance/counter;
            avgLevel = avgLevel/counter;
        
            if (connection==NULL){
                cout<<mysql_error(&mysql)<<endl;
            }

            else{
                string q = "INSERT into sensor VALUES ('" + s.getSensorID() + "','" + to_string(s.getDuration()) + "','" + to_string(s.getTemperature()) + "','" + to_string(avgDistance) + "','" + to_string(avgVolume) + "','" + c.getShapeID() + "',CURRENT_TIMESTAMP());";
                const char* query = q.c_str();  
                mysql_query(connection,query);        
                if (query_state !=0) {
                    cout << mysql_error(connection) << endl;
                }
                cout << "Sending to db\n" << endl;
            }
            counter = 0;
            avgVolume = 0;
            avgDistance = 0;
            avgLevel = 0;
        }
    
    }
    mysql_close(&mysql);
}

void CylinderFunc(Cylinder c){
    Sensors s = c.returnSensor();

    cout<< "Sensor ID: " + s.getSensorID() << endl;
    cout << "Vessel has maximum volume of: " + to_string(c.getMaxVolume()) << endl;
    cout << "This is a " + c.getShapeID() << endl;
    cout << "It has a height, radius of: " << to_string(c.getCylinderHeight()) + " cm, " + to_string(c.getCylinderRadius()) + "cm" << endl;

    cout << "\nHello!\n" << endl;

    mysql_init(&mysql);
    connection = mysql_real_connect(&mysql, ip, usr, pass, db, 0, NULL, 0);

    while(true){
        cout << "Hello before update" << endl; //remove me!
        s.update();
        cout << "Hello after update" << endl;  //remove me!
        float speedOfSoundM = 331+0.6*s.getTemperature();
        float speedOfSoundCM = speedOfSoundM*100;
        float distance = (s.getDuration()/2/1000000)*speedOfSoundCM;
        float level = c.getCylinderHeight() - distance;
        float volume = (M_PI * c.getCylinderRadius() * c.getCylinderRadius()) * level;
        cout << "Hello after calculations" << endl;
        if(volume >= c.getMaxVolume() || volume < 0)
        {
            continue;
        }
        cout << c.getShapeID()+" Container with a volume of "+ to_string(volume)+" and has a water level of "+to_string(level) <<endl;
        cout <<"\n";

        avgVolume = avgVolume + volume;
        avgDistance = avgDistance + distance;
        avgLevel = avgLevel + level;
        counter++;

        if(counter == 10)
        {
            avgVolume = avgVolume/counter;
            avgDistance = avgDistance/counter;
            avgLevel = avgLevel/counter;

            if (connection==NULL){
                cout<<mysql_error(&mysql)<<endl;
            }

            else{
                string q = "INSERT into sensor VALUES ('" + s.getSensorID() + "','" + to_string(s.getDuration()) + "','" + to_string(s.getTemperature()) + "','" + to_string(avgDistance) + "','" + to_string(avgVolume) + "','" + c.getShapeID() + "',CURRENT_TIMESTAMP());";
                const char* query = q.c_str();  
                mysql_query(connection,query);         
                if (query_state !=0) {
                    cout << mysql_error(connection) << endl;
                }
                cout << "Sending to db\n" << endl;
            }
            
            counter = 0;
            avgVolume = 0;
            avgDistance = 0;
            avgLevel = 0;
        }
    }
    mysql_close(&mysql);
}

void CuboidFunc(Cuboid c){
    Sensors s = c.returnSensor();

    cout << "Sensor ID: " + s.getSensorID() << endl;
    cout << "Vessel has maximum volume of: " + to_string(c.getMaxVolume()) << endl;
    cout << "This is a " + c.getShapeID() << endl;
    cout << "It has a height, width and length of: " << to_string(c.getCuboidHeight()) + " cm, " + to_string(c.getCuboidWidth()) + " cm, " + to_string(c.getCuboidLength()) + "cm" << endl;

    mysql_init(&mysql);
    connection = mysql_real_connect(&mysql, ip, usr, pass, db, 0, NULL, 0);

    while(true){
        s.update();
        float speedOfSoundM = 331+0.6*s.getTemperature();
        float speedOfSoundCM = speedOfSoundM*100;
        float distance = (s.getDuration()/2/1000000)*speedOfSoundCM;
        float level = c.getCuboidHeight() - distance;
        float volume = c.getCuboidLength() * c.getCuboidWidth() * level;

         if(volume >= c.getMaxVolume() || volume < 0)
        {
            continue;
        }
        cout << c.getShapeID()+" Container with a volume of "+ to_string(volume)+" cm cubed and has a water level of "+to_string(level) <<endl;
        cout <<"\n";

        avgVolume = avgVolume + volume;
        avgDistance = avgDistance + distance;
        avgLevel = avgLevel + level;
        counter++;

        if(counter == 10)
        {
            avgVolume = avgVolume/counter;
            avgDistance = avgDistance/counter;
            avgLevel = avgLevel/counter;

            if (connection==NULL)
            {
                cout<<mysql_error(&mysql)<<endl;
            }

            else
            {
                string q = "INSERT into sensor VALUES ('" + s.getSensorID() + "','" + to_string(s.getDuration()) + "','" + to_string(s.getTemperature()) + "','" + to_string(distance) + "','" + to_string(volume) + "','" + c.getShapeID() + "', CURRENT_TIMESTAMP());";
                const char* query = q.c_str();   
                mysql_query(connection,query);
                if (query_state !=0) {
                    cout << mysql_error(connection) << endl;
                }
                cout << "Sending to db\n" << endl;
            }

            counter = 0;
            avgVolume = 0;
            avgDistance = 0;
            avgLevel = 0;

        }
    }
    mysql_close(&mysql);
}