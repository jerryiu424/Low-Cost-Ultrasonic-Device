#include "Sensors.cpp"
#define SLEEP 1500000
using namespace std;
     
int main(){
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors())<< endl;    //should be 0
    Sensors first;
    //Sensors second;
    cout << "first sensor has ID: " + first.getSensorID() << endl;
    //cout << "second sensor has ID: " + second.getSensorID() << endl;
    cout << "current number of sensors: " + to_string(Sensors::getNumberOfSensors()) << endl; 

    //print info of first sensor in 1 second increments 10 times
    usleep(SLEEP);
    for (int i = 0; i<10;i++){
        first.updateLine();    //read line, which updates duration and temp
        cout << "first sensor has duration: " + first.getDuration() + " and temp: "+first.getTemperature() << endl;
        usleep(SLEEP);//pause for 1 second
    }
    
    //print info of second sensor in 1 second increments 
    /*
    for (int i = 0; i<10;i++){
        second.updateLine();
        cout << "second sensor has duration: " + second.getDuration() + " and temp: "+second.getTemperature() << endl;
        usleep(SLEEP);//pause for 1 second
    }
    */
    return 0;
}
