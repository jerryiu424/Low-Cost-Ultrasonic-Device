#include "Sensors.cpp"
#define SLEEP 1500000
using namespace std;

void draw(int []);
string multiply(int t);

int main(){
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors())<< endl;    //should be 0
    Sensors first;
    //Sensors second;
    cout << "first sensor has ID: " + first.getSensorID() << endl;
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors()) << endl; 

    usleep(SLEEP);
    for (int i = 0; i<10;i++){
        first.update();    //read line, which updates duration and temp
        cout << "first sensor has duration: " + to_string(first.getDuration()) + " and temp: " + to_string(first.getTemperature()) << endl;
        usleep(SLEEP);//pause for 1 second
    }
    
    return 0;
}